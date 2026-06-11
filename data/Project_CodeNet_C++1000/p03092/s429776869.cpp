#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

typedef long long ll;
typedef pair<ll,ll> P;

const int sz = 5005;
ll dp[sz][sz];
bool used[5555];

int main(){

	ll n, a, b;cin >> n >> a >> b;
	vector<ll> v(n);
	REP(i, n)cin >> v[i],v[i]--;

	REP(i, sz)REP(j, sz)dp[i][j] = LLINF;
	dp[0][0] = 0;

	REP(i, n+1){
		if(i > 0)used[v[i-1]] = true;
		REP(j, n+1){
			if(used[j])dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
			else dp[i][j+1] = min(dp[i][j+1], dp[i][j] + b);
			if(v[i] == j)dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			if(v[i] < j)dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			else dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a);
		}
	}

	cout << dp[n][n] << endl;

	return 0;
}
