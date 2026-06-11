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
		cout << fixed << setprecision(20);
	}
};
initializer _____;
struct range {
	int l, r, c;
	range(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}
	bool operator<(const range &rhs) const {
		return l < rhs.l;
	}
};
bool cmp(const range &r1, const range &r2) {
	if (r1.c != r2.c)
		return r1.c < r2.c;
	else
		return r1.l < r2.l;
}
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	int C;
	cin >> C;
	vector< range > R(N);
	rep(i, N) cin >> R[i].l >> R[i].r >> R[i].c;
	sort(R.begin(), R.end(), cmp);
	vector< range > R2;
	range tmp = R[0];
	for (int i = 1; i < N; i++) {
		if (tmp.c == R[i].c && tmp.r == R[i].l) {
			tmp.r = R[i].r;
		} else {
			R2.push_back(tmp);
			tmp = R[i];
		}
	}
	R2.push_back(tmp);
	sort(R2.begin(), R2.end());
	//rep(i, R2.size()) cout << R2[i].l << " " << R2[i].r << " " << R2[i].c << endl;
	vector< int > A;
	rep(i, R2.size()) {
		range r = R2[i];
		bool f = true;
		rep(j, A.size()) {
			if (A[j] < r.l) {
				f = false;
				A[j] = r.r;
				break;
			}
		}
		if (f)
			A.push_back(r.r);
	}
	cout << A.size() << endl;
	return 0;
}