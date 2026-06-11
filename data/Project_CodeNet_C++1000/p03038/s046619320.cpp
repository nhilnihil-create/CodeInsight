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
	int n, m;
	cin >> n >> m;
	map<ll, ll> mp;
	rep(i,n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	rep(i,m) {
		int a, b;
		cin >> b >> a;
		mp[a] += b;
	}
	vector<pair<ll, ll>> v;
	for (auto p: mp) v.push_back(p);
	sort(ALL(v), greater<>());
	int num = 0;
	ll ans = 0;
	for (auto p: v) {
		if (num == n) break;
		if (num + p.second <= n) {
			ans += p.first * p.second;
			num += p.second;
		} else {
			ans += p.first * (n - num);
			num = n;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}