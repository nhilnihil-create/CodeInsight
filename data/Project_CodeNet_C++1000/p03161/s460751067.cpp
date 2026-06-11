#include<bits/stdc++.h>
using namespace std;
#define inf 1e9 + 5
int main() {
    int n, k;
    cin >> n >> k;
    vector< int > height(n);
    for (int& i: height) cin >> i;
    vector< int > dp (n, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + k; j++) {
            if (j < n) dp[j] = min (dp[j], dp[i] + abs(height[i] - height[j]));
        }
    }
    cout << dp[n - 1];
}