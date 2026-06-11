#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin>>t;
    // while(t--){
        int n; cin>>n;
        vector<double>p(n);
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        vector<double>dp(n+1, 0);
        dp[0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=i;j>=0;j--){
                if(j == 0){
                    dp[j] = (1-p[i-1])*dp[j];
                }else{
                    dp[j] = (1-p[i-1])*dp[j] + p[i-1]*dp[j-1];
                }
            }
        }
        double ans = 0;
        for(int i=0;i<n+1;i++){
            if(2*i>n){
                ans += dp[i];
            }
        }
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        cout << fixed;
        cout << setprecision(10);
        cout << ans << "\n";
    // }
}
