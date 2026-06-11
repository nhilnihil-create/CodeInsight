#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ma = 1000000;
    cin >> n;
    vector<int>dp(n+1,ma);
    dp[n] = 0;
    for(int i = n;i>0; i--){
        dp[i-1] = min(dp[i]+1, dp[i-1]);
        for(int j=1;j<7;j++){
            if(i-pow(6,j)>=0)
            {
                dp[i-pow(6,j)] = min(dp[i]+1, dp[i-pow(6,j)]);
            }
            if(i-pow(9,j)>=0)
            {
                dp[i-pow(9,j)] = min(dp[i]+1, dp[i-pow(9,j)]);
            }
        }
        //cout << i << ":" <<dp[i] << endl;
    }
    cout << dp[0] << endl;
    return 0;
}