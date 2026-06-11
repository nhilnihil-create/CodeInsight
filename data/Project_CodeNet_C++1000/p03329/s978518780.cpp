// 7/15
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i-1] + 1;  // 1を使った場合

        int digit = 6;
        while (true) {
            int now = i - digit;
            if (now >= 0) dp[i] = min(dp[i], dp[now] + 1);
            else break;

            digit *= 6;
        }

        digit = 9;
        while (true) {
            int now = i - digit;
            if (now >= 0) dp[i] = min(dp[i], dp[now] + 1);
            else break;

            digit *= 9;
        }
    }

    cout << dp[N] << endl;
}