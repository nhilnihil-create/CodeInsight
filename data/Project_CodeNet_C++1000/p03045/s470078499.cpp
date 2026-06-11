#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


// union by size + path having
class UnionFind {
public:
		vector <ll> par; // 各元の親を表す配列
		vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

		// Constructor
		UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
				for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
		}
		void init(ll sz_) {
				par.resize(sz_);
				siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
				for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
		}

		// Member Function
		// Find
		ll root(ll x) { // 根の検索
				while (par[x] != x) {
						x = par[x] = par[par[x]]; // x の親の親を x の親とする
				}
				return x;
		}

		// Union(Unite, Merge)
		bool merge(ll x, ll y) {
				x = root(x);
				y = root(y);
				if (x == y) return false;
				// merge technique（データ構造をマージするテク．小を大にくっつける）
				if (siz[x] < siz[y]) swap(x, y);
				siz[x] += siz[y];
				par[y] = x;
				return true;
		}

		bool issame(ll x, ll y) { // 連結判定
				return root(x) == root(y);
		}

		ll size(ll x) { // 素集合のサイズ
				return siz[root(x)];
		}
};

int main()
{
	ll N, M;
	cin >> N >> M;
	UnionFind uf(N);
	REP(i, M) {
		ll X, Y, Z;
		cin >> X >> Y >> Z;
		X--; Y--;
		uf.merge(X, Y);
	}
	set<ll> se;
	REP(i, N) {
		se.insert(uf.root(i));
	}
	PRINT(se.size());
	return 0;
}


