#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n,m;
    cin>>n>>m;

    char v[n][m];
    int dp[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    
    memset(dp,0,sizeof(dp));
    int ans = 0;

    dp[0][0]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='#') continue;
            if(j>0)dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            if(i>0)dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
        }
    }

    cout<<dp[n-1][m-1];
}