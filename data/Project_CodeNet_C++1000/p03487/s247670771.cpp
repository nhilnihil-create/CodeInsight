#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n;
	cin >> n;
	map<ll, ll> mp;
	rep(i,n) {
		ll a;
		cin >> a;
		mp[a]++;
	}
	ll ans = 0;
	for (auto p: mp) {
		ll a = p.first;
		ll cnt = p.second;
		if (cnt < a) ans += cnt;
		else ans += (cnt - a);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}