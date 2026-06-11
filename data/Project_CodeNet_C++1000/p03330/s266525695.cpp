#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll iro[601][601];
signed main() {
	ll n, c, a, cnt = 0, ans = INF; cin >> n >> c;
	vector<ll> v0, v1, v2;
	vector<vector<ll>> v(4, vector<ll>(c + 2));
	for (int h = 1; h <= c; h++) {
		for (int i = 1; i <= c; i++) {
			cin >> iro[h][i];
		}
	}
	for (int h = 1; h <= n; h++) {
		for (int i = 1; i <= n; i++) {
			cin >> a;
			v[(h + i) % 3][a]++;
		}
	}
	for (int h = 1; h <= c; h++) {
		for (int i = 1; i <= c; i++) {
			if (i == h) { continue; }
			for (int j = 1; j <= c; j++) {
				if (h == j || i == j) { continue; }
				cnt = 0;
				for (int k = 1; k <= c; k++) {
					cnt += iro[k][h] * v[0][k];
				}
				for (int k = 1; k <= c; k++) {
					cnt += iro[k][i] * v[1][k];
				}
				for (int k = 1; k <= c; k++) {
					cnt += iro[k][j] * v[2][k];
				}
				ans = min(ans, cnt);
			}
		}
	}
	cout << ans << endl;
	cin >> n; return 0;
}