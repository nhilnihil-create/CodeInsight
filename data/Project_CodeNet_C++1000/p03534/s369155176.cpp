#include<iostream>
#include<algorithm>
#include<string>
int al[4];
int main() {
	std::string S;
	std::cin >> S;
	for (auto u : S) {
		al[u - 'a']++;
	}
	int M = std::max({ al[0],al[1],al[2] });
	int m = std::min({ al[0],al[1],al[2] });
	std::cout << (M - m < 2 ? "YES" : "NO") << std::endl;
	return 0;
}