#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    vector<int> dp(n);
    for(int i=0; i<n; i++) dp[i] = INT_MAX;
    for(int i=0; i<n; i++) cin >> height[i];
    dp[0] = 0;
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=i-k && j>=0; j--) {
            dp[i] = min(dp[i], dp[j]+abs(height[j]-height[i]));
        }
    }
    cout << dp[n-1];
    return 0;
}