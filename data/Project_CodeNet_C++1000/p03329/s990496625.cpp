#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main() {
    int N;
    cin >> N;

    int dp[100100];
    for (int i = 0; i < 100100; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int power = 1;
        while (i + power <= N) {
            dp[i + power] = min(dp[i + power], dp[i] + 1);
            power *= 6;
        }
        power = 9;
        while (i + power <= N) {
            dp[i + power] = min(dp[i + power], dp[i] + 1);
            power *= 9;
        }
    }

    cout << dp[N] << endl;
}