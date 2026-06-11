#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9+100;
const ll INFL = 1e18+100;
const ll MOD = 1e9+7;
const bool debug = 0;
//-----------------------------------------------//

int K;
int dp[112345];

int main() {
	cin >> K;
	
	fill(dp, dp + K, INF);
	queue<int> que;
	que.push(1);
	dp[1] = 1;
	
	while (!que.empty()) {
		int cur = que.front(); que.pop();
		
		int nex = (cur * 10) % K;
		if (chmin(dp[nex], dp[cur])) {
			dp[nex] = dp[cur];
			que.push(nex);
		}
		
		nex = (cur + 1) % K;
		if (chmin(dp[nex], dp[cur] + 1)) {
			dp[nex] = dp[cur] + 1;
			que.push(nex);
		}
	}
	
	cout << dp[0] << endl;
	
	return 0;
}
