#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> stone(n);
    for (int i=0;i<n;i++)
        cin >> stone[i];

    vector<int> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= i + k; j++)
            if(j<n)
                dp[j] = min(dp[j], dp[i] + abs(stone[j] - stone[i]));

    cout << dp[n - 1];
    return 0;
}
