#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define MAX 1000
ll dp[MAX+1][MAX+1];

ll solve(int h, int w)
{
    for(int i=1; i<=w; i++){
        if(dp[1][i]==-1) break;
        dp[1][i]=1;
    }
    for(int i=1; i<=h; i++){
        if(dp[i][1]==-1) break;
        dp[i][1]=1;
    }
    for(int i=2; i<=h; i++){
        for(int j=2; j<=w; j++){
            if(dp[i][j]==-1) continue;
            if(dp[i-1][j]!=-1) {
                dp[i][j]= dp[i-1][j]%mod;
            }
            if(dp[i][j-1]!=-1){
                dp[i][j]= (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    return dp[h][w]%mod;
}

int main()
{
    FASTIO;
    int h,w;
    memset(dp, 0, sizeof dp);
    cin>>h>>w;
    char arr[h+1][w+1];
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='#'){
                dp[i][j]= -1;
            }
        }
    }
    cout<<solve(h, w);
    return 0;
}


