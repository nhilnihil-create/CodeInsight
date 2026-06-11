#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pl = pair<ll, ll>;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	map<int, int> mp;
	repl(i, 2, n + 1) {
		int p = i;
		repl(j, 2, sqrt(i) + 1) {
			while (p % j == 0) {
				p /= j;
				mp[j]++;
			}
		}
		if (p != 1) mp[p]++;
	}
	vector<int> a(100);
	for (auto p : mp) a[p.second + 1]++;
	for (int i = 98; i >= 0; i--) a[i] += a[i + 1];
	int ans = a[75] + a[25] * (a[3] - 1) + a[15] * (a[5] - 1) + a[5] * (a[5] - 1) / 2 * (a[3] - 2);
	cout << ans << endl;
	return 0;
}