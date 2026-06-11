#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#include <sstream>
#include <complex>
#define BIT(nr) (1ULL << (nr))
#define int long long
#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	
#define LL_HALFMAX 9223372036854775807 / 2	
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

using namespace std;

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;

	// libalgo のものに追加、メンバを追加するだけなので互換性は崩さないはず、逆辺のG[e.dstの]インデックスを保持
	int rev;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
	bool operator<(const Edge& right) const {
		return dst < right.dst;
	}
};

using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph& g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph& g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

struct uf_tree {
	std::vector<int> parent;
	int __size;
	uf_tree(int size_) : parent(size_, -1), __size(size_) {}
	void unite(int x, int y) {
		if ((x = find(x)) != (y = find(y))) {
			if (parent[y] < parent[x]) std::swap(x, y);
			parent[x] += parent[y];
			parent[y] = x;
			__size--;
		}
	}
	bool is_same(int x, int y) { return find(x) == find(y); }
	int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
	int size(int x) { return -parent[find(x)]; }
	int size() { return __size; }
};

class Vector3D {
public:
	double x, y, z;
	Vector3D(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3D operator- (Vector3D right) {
		return Vector3D(right.x - x, right.y - y, right.z - z);
	}

	double Length() {
		return sqrtl(x * x + y * y + z * z);
	}
};

bool solve() {
	return false;
}

int mod_pow(int x, int n, int mo) {
	int res = 1;

	while (n > 0) {
		if (n & 1LL) {
			res *= x;
			res %= mo;
		}
		x = x * x % mo;
		n >>= 1;
	}

	return res;
}

#ifdef DEBUG
template <class T>ostream& operator<<(ostream& o, const vector<T>& v)
{
	o << "{"; for (int i = 0; i < (int)v.size(); i++)o << (i > 0 ? ", " : "") << v[i]; o << "}"; return o;
}
#endif // DEBUG

template <class T>ostream& operator<<(ostream& o, const vector<T>& v)
{
	for (int i = 0; i < (int)v.size(); i++)o << (i > 0 ? " " : "") << v[i]; return o;
}
signed main() {
	int N, M, Q;
	cin >> N >> M >> Q;

	vector<int> L(M), R(M), p(Q), q(Q);
	// 2D 累積和
	vector<vector<int>> cum(N + 2, vector<int>(N + 2, 0));
	vector<vector<int>> a(N + 1, vector<int>(N + 1, 0));
	rep(i, M) {
		cin >> L[i] >> R[i];
		a[R[i]][L[i]]++;
	}

	rep(i, Q) {
		cin >> p[i] >> q[i];
	}

	REPS(y, N) {
		REPS(x, N) {
			cum[y + 1][x + 1] = cum[y][x + 1] + cum[y + 1][x] - cum[y][x] + a[y][x];
		}
	}

	rep(i, Q) {
		int x = p[i], y = q[i];

		int ans = cum[y + 1][N + 1] - cum[y + 1][x];
		cout << ans << "\n";
	}

	return 0;
}