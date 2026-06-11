#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll dp[1010][22522];

struct block{
	int w,s;
	ll v;
	bool operator<(const block& rhs){
		return (w+s) < (rhs.w+rhs.s);
	}
};

block b[1010];

int main(void){
	int n,i,j;
	ll ans=0ll;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> b[i].w >> b[i].s >> b[i].v;
	}
	sort(b,b+n);
	for(i=0; i<n; ++i){
		for(j=0; j<22522; ++j){
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		}
		for(j=0; j<=b[i].s; ++j){
			dp[i+1][j+b[i].w] = max(dp[i+1][j+b[i].w],dp[i][j]+b[i].v);
		}
	}
	for(j=0; j<22522; ++j){
		ans = max(ans,dp[n][j]);
	}
	cout << ans << endl;
	return 0;
}
