#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() 
{
	int N;
	std::cin >> N;
	int A;
	std::map<int,int> m;
	for (int i = 0; i < N; ++i) {
		std::cin >> A;
		auto it = m.find(A);
		if (it != m.end()) { // 見つかった
			m.at(A)++;
		} else {
			m.insert({A, 1});
		}
	}

	int k = 0;

	for (auto it = m.begin(); it != m.end(); ++it) {
		int f = it->first;
		int s = it->second;

		if ((s - f) > 0) {
			k += s - f;
		}
		else if ((s - f) < 0) {
			k += s;
		}
	}
	std::cout << k << std::endl;

	return 0;
}
