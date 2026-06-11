#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int dp[k + 1];
    for (int i = 0; i <= k; i++) dp[i] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < a[j]) break;
            if (dp[i - a[j]] == 0) 
            {
                dp[i] = 1;
                break;
            }
        }
    }
    if (dp[k] == 1) cout << "First";
    else cout << "Second";
}