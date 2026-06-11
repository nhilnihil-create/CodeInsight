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
const ll LINF = 0xcccccccccccccccLL;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

#define N 200100
#define uint unsigned int

//head

int n;
uint a[N], b[N], c[N];
uint ans;

inline const uint minus_u(const uint a, const uint b) {return a>b?a-b:0;}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%u", a+i);
	rep(i, n) scanf("%u", b+i);
	rep(i, 29) {
		uint X = (1U<<(i+1)) - 1, T = 1U<<i;
		rep(i, n) c[i] = b[i] & X;
		sort(c, c+n);
		rep(j, n) {
			uint now = a[j] & X;
			uint *itr = lower_bound(c, c+n, minus_u(T, now)), *utr = lower_bound(c, c+n, minus_u(2*T, now));
			ans ^= ((uint)(utr-itr)&1U)<<i;
			itr = lower_bound(c, c+n, minus_u(3*T, now));
			ans ^= ((uint)(c+n-itr)&1U)<<i;
		}
	}
	printf("%u\n", ans);
}