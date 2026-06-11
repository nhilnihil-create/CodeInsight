#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

constexpr ll max_digits = 45;

ll dp[max_digits][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    Vl A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < max_digits; i++) {
        dp[i][0] = dp[i][1] = -1;
    }
    dp[0][0] = 0;

    for (int i = 0; i < max_digits; i++) {
        ll mask = 1LL << (max_digits - 1 - i);
        ll num0 = 0, num1 = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] & mask)
                ++num1;
            else
                ++num0;
        }
        ll cost0 = mask * num1;
        ll cost1 = mask * num0;

        if (dp[i][0] != -1) {
            if (K & mask)
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + cost1);
            else
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + cost0);
        }

        if (dp[i][0] != -1) {
            if (K & mask)
                dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + cost0);
        }

        if (dp[i][1] != -1)
            dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + max(cost0, cost1));
    }

    cout << max(dp[max_digits][0], dp[max_digits][1]) << endl;

    return 0;
}