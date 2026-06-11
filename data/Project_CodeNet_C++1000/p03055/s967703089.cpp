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
int dfs(vector< vector< int > > &G, int x, int p, int &d) {
	int m1 = 0, m2 = 0;
	rep(i, G[x].size()) {
		int j = G[x][i];
		if (j == p)
			continue;
		int tmp = dfs(G, j, x, d);
		if (tmp > m1) {
			m2 = m1;
			m1 = tmp;
		} else if (tmp > m2) {
			m2 = tmp;
		}
	}
	chmax(d, m1 + m2);
	//cout << x << " " << m1 << " " << m2 << endl;
	return m1 + 1;
}
signed main() {
	cin >> N;
	vector< vector< int > > G(N);
	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int d = 0;
	dfs(G, 0, -1, d);
	++d;
	vector< int > dp(d + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= d; i++) {
		if (i == 2)
			dp[i] = 0;
		else {
			if (dp[i - 1] == 0 || dp[i - 2] == 0)
				dp[i] = 1;
			else
				dp[i] = 0;
		}
	}
	//cout << d << endl;
	string ans = dp[d] ? "First" : "Second";
	cout << ans << endl;
	return 0;
}