#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    int q[n+2];
    for (int i=1; i<=n; i++)
        cin>>q[i];
        
    int dp[n+2];
    memset(dp,0x3f3f3f3f,sizeof(dp));
    
    dp[1] = 0;
    dp[2] = abs(q[1]-q[2]);
    
    for (int i=3; i<=n; i++){
        for (int j=1; j<=k; j++){
            if (i-j<1) break;
            dp[i] = min(dp[i], dp[i-j] + abs(q[i]-q[i-j]));
        }
        //cout<<i<<" "<<dp[i]<<endl;
    }
        
        
    cout<<dp[n];
}