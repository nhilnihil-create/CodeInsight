#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> height(n);
    for(long long i=0; i<n; i++) cin >> height[i];
    vector <long long> dp(n);
    dp[0] = 0;
    dp[1] = abs(height[1]-height[0]);
    for(long long i=2; i<n; i++) {
        dp[i] = min(dp[i-1]+abs(height[i]-height[i-1]), dp[i-2]+abs(height[i]-height[i-2]));
    }
    cout << dp[n-1];
    return 0;
}
