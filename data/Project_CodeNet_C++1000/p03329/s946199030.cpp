#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int min(int a, int b) { return (a < b) ? a : b; }

int main() {
    int n;
    cin >> n;

    int *dp = new int[n + 10];
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        int nine = 9, six = 6;
        while (i >= nine) {
            dp[i] = min(dp[i], dp[i - nine] + 1);
            nine *= 9;
        }
        while (i >= six) {
            dp[i] = min(dp[i], dp[i - six] + 1);
            six *= 6;
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[n] << endl;
    return 0;
}