#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1e9+100;
const ll MOD = 1000000007;
const double EPS = 1e-10;
const bool debug = 0;
//------------------------------//

string s;
int dp[1<<26];

int main() {
	cin >> s;
	int N = s.size();
	REP(i, N) s[i] -= 'a';
	
	fill(dp, dp + (1<<26), INF);
	
	int x = 0;
	dp[0] = 0;
	REP(i, N) {
		x ^= 1<<s[i];
		REP(j, 26) chmin(dp[x], dp[x ^ 1<<j] + 1);
	}
	
	cout << max(dp[x], 1) << endl;
	
	return 0;
}
