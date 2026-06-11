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

map<int, int> mp2;

int dfs(int count, vector<int> A, int sum, int targetValue, int minCount) {
	if (mp2[targetValue - sum] != 0) {
		return min(minCount, count + mp2[targetValue - sum]);
	}

	if (sum == targetValue) {
		return min(minCount, count);
	}
	else if (targetValue < sum) {
		return minCount;
	}

	for (size_t i = 0; i < A.size(); ++i) {
		int buf = dfs(count + 1, A, sum + A[i], targetValue, minCount);
		if (buf < minCount) {
			minCount = min(minCount, buf);
		}
	}

	return minCount;
}

int main() {
	int N;
	cin >> N;
	vector<int> A;
	map<int, bool> mp;

	A.push_back(1);
	for (int i = 1;; ++i) {
		if (mp[pow(9, i)] == 0 && pow(9, i) <= N) {
			A.push_back(pow(9, i));
			mp[pow(9, i)] = 1;
		}
		else {
			break;
		}
	}

	for (int i = 1;; ++i) {
		if (mp[pow(6, i)] == 0 && pow(6, i) <= N) {
			A.push_back(pow(6, i));
			mp[pow(6, i)] = 1;
		}
		else {
			break;
		}
	}

	sort(A.rbegin(), A.rend());


	for (int i = 1; i <= N; ++i) {
		int minCount = INT_MAX;
		int count = 0;
		count = dfs(0, A, 0, i, minCount);
		mp2[i] = count;
	}

	cout << mp2[N] << endl;

	return 0;
}