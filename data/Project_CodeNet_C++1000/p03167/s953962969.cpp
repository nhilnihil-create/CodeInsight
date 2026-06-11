#include<bits/stdc++.h>
using namespace std;
#define ll long long

char mat[1002][1002];
ll dp[1002][1002];
ll mod = 1e9+7;

ll grid(ll r, ll c,ll h, ll w){
	if(r==h && c==w)
		return 1;
	if(r>h || c>w)
		return 0;
	
	if(dp[r][c]!=-1)
		return dp[r][c];

	if(mat[r][c]=='.')
		return dp[r][c] = (grid(r+1,c,h,w)%mod + grid(r,c+1,h,w)%mod)%mod;
	else
		return dp[r][c] = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++){
    	for(int j=1;j<=w;j++){
    		cin>>mat[i][j];
    	}
    }
    memset(dp,-1,sizeof(dp));
    cout<<grid(1,1,h,w);
}
