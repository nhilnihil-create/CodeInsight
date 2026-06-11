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
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	vector<ll> sum(n+1);
	rep(i,n) sum[i+1] = sum[i] + v[i];
	map<ll, ll> mp;
	rep(i,n+1) mp[sum[i]]++;
	ll ans = 0;
	for (auto p: mp) {
		ans += (p.second * (p.second - 1)) / 2ll;
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}