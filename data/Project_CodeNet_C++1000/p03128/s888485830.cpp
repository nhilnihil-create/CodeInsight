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
signed main() {
	cin >> N >> M;
	vector< int > A(M);
	rep(i, M) cin >> A[i];
	sort(A.begin(), A.end());
	vector< pii > dp(N + 1, pii(-1, 0));
	dp[0] = pii(0, 0);
	int table[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	rep(k, M) {
		int a = A[k];
		rep(i, N) {
			if (dp[i].first != -1 && i + table[a] <= N) {
				if (dp[i + table[a]].first <= dp[i].first + 1) {
					if (dp[i + table[a]].first == dp[i].first + 1) {
						chmax(dp[i + table[a]].second, a);
					} else {
						dp[i + table[a]].first = dp[i].first + 1;
						dp[i + table[a]].second = a;
					}
				}
			}
		}
	}
	vector< int > ans;
	int i = N;
	while (i > 0) {
		ans.push_back(dp[i].second);
		i -= table[dp[i].second];
	}
	sort(ans.rbegin(), ans.rend());
	rep(i, ans.size()) cout << ans[i];
	cout << endl;
	return 0;
}