#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
#define MOD2 998244353
#define int long long
//#define PI 3.14159265358979

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template < typename T >
ostream &operator<<(ostream &os, const vector< T > &A) {
	for (int i = 0; i < A.size(); i++)
		os << A[i] << " ";
	os << endl;
	return os;
}
template <>
ostream &operator<<(ostream &os, const vector< vector< int > > &A) {
	int N = A.size();
	int M;
	if (N > 0)
		M = A[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c;
	edge(int _from = 0, int _to = 0, int _d = 0, int _c = 0) {
		from = _from;
		to = _to;
		d = _d;
		c = _c;
	}
	bool operator<(const edge &rhs) const {
		return (d == rhs.d) ? (c < rhs.c) : (d < rhs.d);
	}
};
struct aabb {
	int x1, y1, x2, y2;
	aabb(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

typedef vector< edge > edges;
typedef vector< edges > graph;
struct flow {
	int to, cap, rev, cost;
	flow(int to = 0, int cap = 0, int rev = 0, int cost = 0) : to(to), cap(cap), rev(rev), cost(cost) {}
};
typedef vector< vector< flow > > flows;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};
const int ci[5] = {0, 0, -1, 0, 1};
const int cj[5] = {0, -1, 0, 1, 0};
const ll LINF = LLONG_MAX / 2;
const int INF = INT_MAX / 2;
const double PI = acos(-1);

int pow2(int n) { return 1 << n; }
template < typename T, typename U >
bool chmin(T &x, const U &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template < typename T, typename U >
bool chmax(T &x, const U &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

struct initializer {
	initializer() {
		cout << fixed << setprecision(11);
	}
};
initializer _____;
struct range {
	int l, r, c;
	range(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}
	bool operator<(const range &rhs) const {
		return l > rhs.l;
	}
};
bool rcomp(const range &lhs, const range &rhs) {
	return lhs.r < rhs.r;
}
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	vector< range > v1(N), v2(N);
	vector< bool > done(N, false);
	rep(i, N) {
		int L, R;
		cin >> L >> R;
		v1[i] = range(L, R, i);
		v2[i] = range(L, R, i);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), rcomp);
	vector< int > s1(N + 1), s2(N + 1);
	rep(i, N) s1[i + 1] = s1[i] + v1[i].l * 2;
	rep(i, N) s2[i + 1] = s2[i] + v2[i].r * 2;
	int ans = 0;
	rep(l, N + 1) for (int r = l - 1; r <= l + 1; r++) {
		if (r < 0 || r > N)
			continue;
		chmax(ans, s1[l] - s2[r]);
	}
	cout << ans << endl;
	return 0;
}