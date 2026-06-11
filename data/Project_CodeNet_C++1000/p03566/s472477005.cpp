#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
#include <map>
#include <set>

using namespace std;
using P = pair<int, int>;
using T = tuple<int, int, int>;

long long MOD = 1000000007;
long long dp[100005][4];

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {

	int N;
	cin >> N;

	vector<int>t(N);
	vector<double>v(N);

	int tSum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> t[i];
		tSum += t[i];
	}
	for (int i = 0; i < N; ++i)cin >> v[i];

	int length = 2 * tSum + 1;
	vector<double>train(length,100000);
	int start = 0;
	int end = 0;
	for (int i = 0; i < N; ++i) {
		start = end;
		end = start + t[i] * 2;
		for (int j = start; j <= end; ++j) {
			//境目は値の小さい方に引っ張られる
			train[j] = min(v[i],train[j]);
		}
	}

	train[0] = 0;
	train[length - 1] = 0;

	for (int i = 1; i < length; ++i) {
		train[i] = min(train[i - 1] + 0.5, train[i]);
	}
	for (int i = length - 2; 0 <= i; --i) {
		train[i] = min(train[i + 1] + 0.5, train[i]);
	}

	double ans = 0;
	for (int i = 1; i < length; ++i) {
		ans += (train[i - 1] + train[i]) * 0.5 / 2.0;
	}

	printf("%.4f\n", ans);
	return 0;
}
