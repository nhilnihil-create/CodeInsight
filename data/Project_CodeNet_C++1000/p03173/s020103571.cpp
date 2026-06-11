//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0xccccccc;
const ll LINF = 922337203685477580LL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

const int N = 410;

//head

int n;
int _[N];
ll __[N];
ll dp[N][N];

ll dfs(int l, int r) {
	if(dp[l][r] != -1) return dp[l][r];
	ll &res = dp[l][r] = LINF;
	if(r-l == 1) return res = 0;
	for(int i = l+1; i < r; i++) {
		chmin(res, dfs(l, i) + dfs(i, r) + __[r]-__[l]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	rep(i, n) cin >> _[i];
	rep(i, n) __[i+1] = __[i] + _[i];
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, n) << endl;
}