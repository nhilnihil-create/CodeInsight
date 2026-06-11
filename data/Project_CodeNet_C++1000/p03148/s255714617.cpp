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
struct sushi {
	int t, d, i;
	sushi(int l = 0, int r = 0, int c = 0) : t(l), d(r), i(c) {}
	bool operator<(const sushi &rhs) const {
		return d < rhs.d;
	}
};
signed main() {
	cin >> N >> K;
	vector< int > D(N), T(N);
	rep(i, N) cin >> T[i] >> D[i];
	vector< sushi > S(N);
	rep(i, N) {
		S[i] = sushi(T[i] - 1, D[i], i);
	}
	sort(S.rbegin(), S.rend());
	vector< int > best(N);
	rep(i, N) chmax(best[S[i].t], S[i].d);
	vector< int > count(N, 0);
	int ans = 0;
	int tmp = 0;
	int x = 0;
	stack< sushi > sk;
	rep(i, K) {
		sushi s = S[i];
		tmp += s.d;
		sk.push(s);
		if (!count[s.t])
			x++;
		count[s.t]++;
	}
	ans = tmp + x * x;
	int i = K;
	while (i < N && sk.size() > 0) {
		sushi s = sk.top();
		//cout << s.d << " " << s.i << endl;
		sk.pop();
		if (count[s.t] > 1) {
			count[s.t]--;
			tmp -= s.d;
			while (i < N && count[S[i].t])
				i++;
			if (i >= N)
				break;
			tmp += S[i].d;
			count[S[i].t]++;
			x++;
			chmax(ans, tmp + x * x);
		}
	}
	cout << ans << endl;
	return 0;
}