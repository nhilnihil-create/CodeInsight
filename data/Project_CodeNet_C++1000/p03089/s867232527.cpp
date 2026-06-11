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
	pair<int, int> a[n];
	rep(i, n) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	vector<int> ans;
	rep(i, n) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[j].first == 0) continue;
			if (a[j].first == a[j].second) {
				a[j].first = 0;
				ans.push_back(a[j].second);
				break;
			} else
				a[j].second--;
		}
	}
	reverse(all(ans));
	if (ans.size() == n) {
		for (auto p : ans) cout << p << endl;
	} else
		cout << -1 << endl;
	return 0;
}