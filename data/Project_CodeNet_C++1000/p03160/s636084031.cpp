#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int heights[n];
    int dp[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++) {
        int x = dp[i-1] + abs(heights[i-1] - heights[i]);
        int y = dp[i-2] + abs(heights[i-2] - heights[i]);
        dp[i] = min(x, y);
    }
    cout <<  dp[n-1] << "\n";
    return 0;
}
