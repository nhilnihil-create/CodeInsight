#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;
const double PI = acos(-1);

int n, a, b, c;
vector<int> l;

int dfs(int cur, int a_, int b_, int c_) {
	if (cur == n) {
		if (!a_ || !b_ || !c_) return INF;	//一本は使う
		return abs(a - a_) + abs(b - b_) + abs(c - c_);
	}
	int r0 = dfs(cur + 1, a_         , b_         , c_         );
	int r1 = dfs(cur + 1, a_ + l[cur], b_         , c_         ) + (a_ ? 10 : 0);
	int r2 = dfs(cur + 1, a_         , b_ + l[cur], c_         ) + (b_ ? 10 : 0);
	int r3 = dfs(cur + 1, a_         , b_         , c_ + l[cur]) + (c_ ? 10 : 0);
	return min(r0, min(r1, min(r2, r3)));
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	cin >> n >> a >> b >> c;
	l.resize(n);
	rep(i, n) cin >> l[i];

	out(dfs(0, 0, 0, 0));

	return 0;
}