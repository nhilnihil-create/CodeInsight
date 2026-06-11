#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define mod         1000000007
#define FAST        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
int compatible[22][22];
int dp[22][(1<<22)];

int solve(int i,int wset){
    if(i == (n+1)){
        if(wset == 0)
            return 1;
        else
            return 0;
    }

    if(dp[i][wset] != -1)
        return dp[i][wset];

    int ans = 0;
    for(int j=0;j<n;j++){
        bool available = (((1<<j)&(wset)) == 0) ? 0 : 1;
        if(available && compatible[i][j]){
            ans = (ans + solve(i+1, (wset^(1<<j)) ) ) % mod;
        }
    }
    dp[i][wset] = ans;

    return ans;
}

int32_t main() {
    FAST;
    cin>>n;
    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            cin>>compatible[i][j];
        }
    }
    int x = (1<<n) - 1;
    cout<<solve(1,x);
}
