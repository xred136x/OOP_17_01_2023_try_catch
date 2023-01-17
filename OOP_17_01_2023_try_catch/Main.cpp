#include<iostream>
#include<vector>
#include<utility>
#include<tuple>
#include<unordered_map>

class DataManager {
	std::vector<int> _keys = { 1,1,2,2,4,2,6,7,7,7,2 };
public:
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount;
		for (size_t i = 0; i < _keys.size(); i++) {
			const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 });
			if (!isInserted) {
				auto value = it->second;// можно int
				value++;
				keyAmount[_keys[i]] = value;
			}
		}
		// бежим по мапу
		std::pair<int, int> key_biggesValue = { 0,0 };
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {
			if (key_biggesValue.second < it->second) {
				key_biggesValue = std::make_pair(it->first, it->second);
			}
		}
		return key_biggesValue.first;
	}
};

int divide(int a, int b) {
	if (b == 0) {
		throw "division by zero";
	}
	return a / b;
}
int errorFunc() {
	throw 0;
	return 1;
}

int main() {
	// class DataManager
	/*DataManager dm;
	std::cout << dm.mostSearchedKey() << '\n';*/
	/*std::tuple<int, std::string, double, float> t {1, "Cat", 1.5, 2.7f};
	const auto& [a, b, c, d] = t;
	std::tuple<int, int, double> t2;
	std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	std::cout << std::get<1>(t) << '\n';
	std::vector<std::tuple<int, double, std::string>> vec;
	vec.push_back({ 1,2.5,"Bob" });
	vec.push_back({ 2,3.14,"Alice" });
	for (size_t i = 0; i < vec.size(); i++) {
		const auto& [x, y, z] = vec[i];
		std::cout << x << ' ' << y << ' ' << z << '\n';
	}*/
	
	// try, catch
	/*int x = 10, y = 0;
	try {
		errorFunc();
		std::cout << divide(x, y) << '\n';
	}
	catch (const char* msg) {
		std::cerr << msg << '\n';
	}
	catch (...) {// catch all - bad practice ипользуется в иск-х случ-х
		std::cerr << "Some exception has occured" << '\n';
	}*/
	std::vector<int> v{ 1,2,3 };
	try {
		int z = v.at(10);
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << '\n';
	}

	return 0;
}