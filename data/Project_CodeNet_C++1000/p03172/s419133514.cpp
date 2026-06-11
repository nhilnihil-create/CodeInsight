#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    
    int dp[n+1][k+1];
    dp[0][0]=1;
    for(int i=1;i<=k;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        vector<int> pref(k+1);
        pref[0] = dp[i-1][0];
        for(int j=1;j<=k;j++)
            pref[j] = (pref[j-1]+dp[i-1][j])%MOD;
        for(int j=0;j<=k;j++){
            if(arr[i]>=j)
                dp[i][j] = pref[j];
            else
                dp[i][j] = (pref[j] - pref[j-arr[i]-1]+MOD)%MOD;
        }
        pref.clear();
    }
    
    cout<<dp[n][k]<<"\n";
}