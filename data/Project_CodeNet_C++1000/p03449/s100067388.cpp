#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	vector<int> A1(N);
	vector<int> A2(N);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A1[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> A2[i];
	}

	int sum1 = 0;
	for (int i = 0; i < N; ++i) {
		sum1 += A1[i];
		int sumTotal = sum1;
		for (int j = i; j < N; ++j) {
			sumTotal += A2[j];
		}
		ans = max(ans, sumTotal);
	}
	cout << ans << endl;

	return 0;
}
