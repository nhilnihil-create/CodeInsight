#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
#define ll long long
//ll dp[100][100001];


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin>>n>>s;
    long long dp[n + 1][n + 1];
    memset(dp, 0 , sizeof(dp));
    for(int i = 1; i <= 1 ; i++){
        dp[i][0] = 1;
    }
    long long presum[n+1] = {0};
    for(int i = 1 ; i <= n ; i++){
        presum[i] = presum[i-1] + dp[i][0];
        presum[i] = presum[i]%mod;
    }
    for(int j = 0 ; j < n - 1; j++){
        for(int i = 1 ; i <= j+2 ; i++){
            if(s[j] == '>'){
                dp[i][j+1] +=(presum[n] - presum[i-1]);
                dp[i][j+1] = dp[i][j+1]%mod;
                if(dp[i][j + 1] < 0)dp[i][j+1] += mod;
            }else if(s[j] == '<'){
                dp[i][j+1] += presum[i-1];
                dp[i][j+1] = dp[i][j+1]%mod;
            }  
        }
        for(int i = 1 ; i <= n ; i++){
        presum[i] = presum[i-1] + dp[i][j+1];
        presum[i] = presum[i]%mod;
        }
    }
    // for(int i = 0 ; i <= n ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<presum[n]<<endl;
    return 0;
}
