#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (int)(s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
constexpr long long INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	string s;
	cin >> s;
	int flg = 1;
	vector<int>dp(1<<26,333333);
	dp[0] = 0;
	int now = 0;
	REP(i,s.size()){
		now ^= 1 << (s[i] - 'a');
		REP(j,26){
			CHMIN(dp[now],dp[now^(1<<j)]+1);
		}
	}
	if(now)cout << dp[now] << endl;
	else cout << 1 << endl;
}