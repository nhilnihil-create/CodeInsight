#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t N, cnt = 0;

void solve(int64_t n, vector<bool> v) {
	if ((count(v.begin(), v.end(), 1) == 3) && (n <= N)) {
		cnt++;
	}

	if (n > N) return;
	else {
		auto v1 = v;
		auto v2 = v;
		auto v3 = v;
		v1.at(0) = 1;
		v2.at(1) = 1;
		v3.at(2) = 1;
		solve(10 * n + 3, v1);
		solve(10 * n + 5, v2);
		solve(10 * n + 7, v3);
	}
}

int main() {
	cin >> N;

	vector<bool> v(3);
	int64_t n = 0;
	solve(n, v);

	cout << cnt << endl;
}