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
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const double PI = acos(-1);

struct UnionFind {
	std::vector<int> par;

	UnionFind(int n) : par(n, -1)
	{
	}

	int root(int x) {
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) std::swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[root(x)];
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n, m;
	cin >> n >> m;

	vector<int> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}

	UnionFind uf(n);

	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		uf.merge(x, y);
	}

	int cnt = 0;
	rep(i, n) {
		if (uf.issame(i, p[i])) {
			cnt++;
		}
	}

	out(cnt);

	return 0;
}