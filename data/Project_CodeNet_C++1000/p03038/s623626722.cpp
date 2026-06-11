#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

typedef pair<ll, ll> pll;

int main() {
	int n, m;
	cin >> n >> m;
	map<ll, ll> mp;
	rep(i,n) {
		ll a;
		cin >> a;
		mp[a]++;
	}
	rep(i,m) {
		ll b, c;
		cin >> b >> c;
		mp[c] += b;
	}
	ll ans = 0;
	ll t = 0;
	vector<pll> v;
	for (auto p: mp) v.push_back(p);
	sort(ALL(v), greater<>());
	for (auto p: v) {
		if (t == n) break;
		if (t + p.second <= n) {
			ans += p.first * p.second;
			t += p.second;
		} else {
			ans += p.first * (n - t);
			t = n;
		}
	}
	cout << ans << endl;
}