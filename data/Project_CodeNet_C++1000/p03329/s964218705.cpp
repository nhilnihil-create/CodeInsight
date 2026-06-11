#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1);

    dp[0]=0;

    for(int i=1; i<=n; i++){
        for(int p6 = 1; p6 <= n; p6*=6){
            if(i - p6 < 0) continue;
            dp[i] = min(dp[i-1]+1, dp[i - p6]+1);
        }
        for(int p9=1; p9 <= n; p9*=9){
            if(i-p9 < 0) continue;
            dp[i] = min(dp[i], dp[i-p9]+1);
        }
    }    
    

    cout << dp[n] << endl;
}