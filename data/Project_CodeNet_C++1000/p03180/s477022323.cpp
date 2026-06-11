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

const int N = 1<<16;

//head

int n;
int a[20][20];
ll sum[N];
ll dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(i, 1<<n) {
		rep(j, n) if(i>>j&1) rep(k, j) if(i>>k&1) sum[i] += a[k][j];
	}
	rep(i, 1<<n) {
		for(int j = i; j > 0;) {
			j--;
			j &= i;
			int u = i^j;
			chmax(dp[i], dp[j] + sum[u]);
		}
	}

	cout << dp[(1<<n)-1] << endl;
}