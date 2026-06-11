#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int q[n+2];
    for (int i=1; i<=n; i++)
        cin>>q[i];
        
    int dp[n+2];
    
    dp[1] = 0;
    dp[2] = abs(q[1]-q[2]);
    
    for (int i=3; i<=n; i++)
        dp[i] = min(dp[i-1] + abs(q[i]-q[i-1]), dp[i-2] + abs(q[i]-q[i-2]));
        
    cout<<dp[n];
}