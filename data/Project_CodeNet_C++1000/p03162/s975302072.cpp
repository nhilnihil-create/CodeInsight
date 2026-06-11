#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n], b[n], c[n], dp[n][4];
    
    for (int i=0; i<n; i++)
        cin>>a[i]>>b[i]>>c[i];
        
    dp[0][1] = a[0];
    dp[0][2] = b[0];
    dp[0][3] = c[0];
    
    for (int i=1; i<n; i++){
        dp[i][1] = a[i] + max(dp[i-1][2], dp[i-1][3]);
        dp[i][2] = b[i] + max(dp[i-1][1], dp[i-1][3]);
        dp[i][3] = c[i] + max(dp[i-1][2], dp[i-1][1]);
    }
    
    cout<<max(dp[n-1][1], max(dp[n-1][2], dp[n-1][3]));
}