#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9+7;

int main(){
    int N;
    cin>>N;
    vector<int> dp(100000+10,INF);
    dp[0] = 0;

    for(int i=0; i<=N; i++){
        for(int j=1; j<=N; j*= 6){
            if(i-j >= 0) dp[i] = min(dp[i-j]+1,dp[i]);
        }

        for(int j=1; j<=N; j *= 9){
            if(i - j >= 0) dp[i] = min(dp[i-j]+1,dp[i]);
        }
    }

    cout<<dp[N]<<endl;
}