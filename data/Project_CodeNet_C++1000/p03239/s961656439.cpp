#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, T;
	cin >> N >> T;

	int ans = INF;
	for (int i = 0; i < N; i++) {
		int c, t;
		cin >> c >> t;
		if (t <= T) ans = min(ans, c);
	}

	if (ans == INF) cout << "TLE" << endl;
	else cout << ans << endl;
}