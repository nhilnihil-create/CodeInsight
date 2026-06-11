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

int N, M, K, T, Q;
string S;
vector< pair< char, char > > query;
int check(int m) {
	int i = m;
	rep(j, Q) {
		char t = query[j].first, d = query[j].second;
		if (S[i] == t) {
			if (d == 'L') {
				--i;
			} else {
				++i;
			}
		}
		if (i == -1)
			return -1;
		if (i == N)
			return 1;
	}
	return 0;
}
signed main() {
	cin >> N >> Q;
	cin >> S;
	query.resize(Q);
	rep(i, Q) cin >> query[i].first >> query[i].second;
	int l = -1, r = N;
	int ls, rs;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int f = check(m);
		if (f == -1) {
			l = m;
		} else {
			r = m;
		}
	}
	ls = l;
	l = -1;
	r = N;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int f = check(m);
		if (f == 1) {
			r = m;
		} else {
			l = m;
		}
	}
	rs = r;
	int ans = rs - ls - 1;
	cout << ans << endl;
	return 0;
}