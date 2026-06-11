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
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}



//head



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vi sum(n+1);
	rep(i, n) {
		sum[i+1] = sum[i] ^ (1<<(s[i]-'a'));
	}

	vi dp(1<<26, INF);
	dp[0] = 0;
	rep(i, n-1) {
		rep(j, 26) {
			chmin(dp[sum[i+1]], dp[sum[i+1]^(1<<j)]+1);
		}
	}

	int ans = dp[sum[n]]+1;
	rep(i, 26) {
		chmin(ans, dp[sum[n]^(1<<i)]+1);
	}

	cout << ans << endl;
}