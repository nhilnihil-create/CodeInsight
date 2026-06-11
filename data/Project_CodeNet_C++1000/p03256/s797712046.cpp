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

int N, M, K, T, Q, H, W;
bool dfs(vector< vector< int > > &G, vector< bool > &done, set< int > &s, int x) {
	done[x] = true;
	s.insert(x);
	rep(i, G[x].size()) {
		int j = G[x][i];
		if (s.find(j) != s.end())
			return true;
		if (done[j])
			continue;
		if (dfs(G, done, s, j))
			return true;
	}
	s.erase(x);
	return false;
}
signed main() {
	cin >> N >> M;
	string S;
	cin >> S;
	vector< vector< int > > G(N * 4);
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		if (S[a] == 'A' && S[b] == 'A') {
			G[a].push_back(b + N);
			G[b].push_back(a + N);
		} else if (S[a] == 'B' && S[b] == 'B') {
			G[a + 2 * N].push_back(b + 3 * N);
			G[b + 2 * N].push_back(a + 3 * N);
		} else if (S[a] == 'A' && S[b] == 'B') {
			G[a + N].push_back(b + 2 * N);
			G[b + 3 * N].push_back(a);
		} else if (S[a] == 'B' && S[b] == 'A') {
			G[a + 3 * N].push_back(b);
			G[b + N].push_back(a + 2 * N);
		}
	}
	vector< bool > done(N * 4);
	set< int > s;
	string ans = "No";
	rep(i, 4 * N) {
		if (!done[i]) {
			if (dfs(G, done, s, i)) {
				ans = "Yes";
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}