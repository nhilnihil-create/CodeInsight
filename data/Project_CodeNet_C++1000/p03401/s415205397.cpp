#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N;
	cin >> N;

	vector<int> vec(N + 2);
	int sumCost = 0;
	{
		int buf = 0;
		for (int i = 0; i < N; ++i) {
			cin >> vec[i + 1];

			sumCost += abs(buf - vec[i + 1]);
			buf = vec[i + 1];
		}

		vec[0] = 0;
		vec[N + 1] = 0;
		sumCost += abs(buf - 0);
	}

	for (size_t i = 1; i < vec.size() - 1; ++i) {
		int cost = sumCost;
		int buf = abs(vec[i] - vec[i - 1]) + abs(vec[i] - vec[i + 1]);

		cost = cost - buf + abs(vec[i - 1] - vec[i + 1]);
		cout << cost << endl;
	}

	return 0;
}