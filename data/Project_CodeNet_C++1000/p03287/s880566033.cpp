#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> sum(n + 1);
	rep(i, n) sum[i + 1] = sum[i] + a[i];
	rep(i, n + 1) {
		sum[i] %= m;
	}
	map<ll, ll> mp;
	rep(i, n + 1) {
		mp[sum[i]]++;
	}
	ll ans = 0;
	for (auto& c : mp) {
		ll tmp = c.second*(c.second - 1) / 2;
		if (tmp == 0) continue;
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}
