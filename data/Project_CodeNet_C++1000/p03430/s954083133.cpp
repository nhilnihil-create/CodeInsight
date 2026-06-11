// Do you knOW what it feels like?

		// To be TorTured by your own MinD?

	// I don't wanna feel the PAIN.

// I BeG you to KILL me, pleASE...

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Os")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

typedef int ll;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=3e2+10, lg=20, mod=1e9+7, inf=1e18;

string s;
ll k,dp[maxn][maxn][maxn],ans=1;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>s>>k;
	for(int i=0;i<SZ(s);i++)for(int j=0;j<=k;j++) dp[i][i][j]=1;
	for(int t=2;t<=SZ(s);t++)for(int l=0,r;l<=SZ(s)-t;l++){	r=l+t-1;
		for(int tg=0;tg<=k;tg++){
			dp[l][r][tg]=max(dp[l+1][r][tg],dp[l][r-1][tg]);
			if(tg!=0 || s[l]==s[r]) dp[l][r][tg]=max(dp[l][r][tg],dp[l+1][r-1][tg-(s[l]!=s[r])]+2);
			ans=max(ans,dp[l][r][tg]);
		}
		//cout<<l<<' '<<r<<' '<<dp[l][r][1]<<endl;
	}
	cout<<ans;
	
	return 0;
}

















