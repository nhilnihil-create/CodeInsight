#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N, K;
	cin >> N >> K;

	vector<int64_t> v(K);
	for (int i = 1; i <= N; i++) {
		v.at(i % K)++;
	}

	if (K % 2) {
		int64_t n = v.at(0) * v.at(0) * v.at(0);
		cout << n << endl;
	}
	else {
		int64_t n = v.at(0) * v.at(0) * v.at(0);
		int64_t m = v.at(K / 2) * v.at(K / 2) * v.at(K / 2);
		cout << n + m << endl;
	}
}