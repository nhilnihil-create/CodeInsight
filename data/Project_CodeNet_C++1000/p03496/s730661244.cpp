#include<math.h>
#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<array>
#include<tuple>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
//AtCoderC++.cpp

using namespace std;

int main() {
	int N; cin >> N;
	auto as = vector<int>(N);
	int max_abs = 0;
	bool plus = false; int index = 0;
	for (size_t i = 0; i < N; i++) {
		cin >> as[i];
		if (max_abs < abs(as[i])) {
			max_abs = abs(as[i]);
			plus = (as[i] >= 0);
			index = i;
		}
	}
	auto steps = vector<pair<int, int>>();
	for (size_t i = 0; i < N; i++) {
		if (i != index) {
			as[i] += as[index];
			steps.push_back({ index + 1, i + 1 });
		}
	}
	if (plus) {
		for (size_t i = 0; i < N - 1; i++) {
			if (as[i] > as[i + 1]) {
				as[i + 1] += as[i];
				steps.push_back({ i + 1, i + 2 });
			}
		}
	} else {
		for (size_t i = N - 1; i > 0; i--) {
			if (as[i - 1] > as[i]) {
				as[i - 1] += as[i];
				steps.push_back({ i + 1, i });
			}
		}
	}
	cout << steps.size() << endl;
	for (size_t i = 0; i < steps.size(); i++) cout << steps[i].first << " " << steps[i].second << endl;
}
