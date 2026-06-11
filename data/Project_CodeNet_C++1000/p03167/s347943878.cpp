#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll mod=1000000007;
const char nl='\n';


void solve(){
    ll i,j,k,l,m,n,u,v;
    cin>>n>>m;
    vector< string> g(n);
    vector<vector<ll> > dp(n+1,vector<ll>(m+1,0));
    for(i=0;i<n;i++) cin>>g[i];
    dp[0][1]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(g[i-1][j-1]=='#') continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }

    cout<<dp[n][m]<<nl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1,i=1;
//    cin >> t;
	while (t--)
	{
//	    cout<<"Case #"<< i++ <<": ";
		solve();
	}
	return 0;
}

