#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int comp[n][n];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin>>comp[i][j];
    
    vector<int> dp(1<<n); // 1<<n mask to check which women are assigned
    dp[0] = 1;
    for(int i=0;i<(1<<n);i++){
        int m = __builtin_popcount(i);
        for(int w = 0; w < n; w++){ // which woman
            if(!(i & 1<<w) && comp[m][w]){ // if we can assign
                int j = i | (1<<w);  //then assign
                dp[j] += dp[i];
                dp[j] %= (1000000007);
            }
        }
    }
    cout<<dp[(1<<n) - 1];
    
}