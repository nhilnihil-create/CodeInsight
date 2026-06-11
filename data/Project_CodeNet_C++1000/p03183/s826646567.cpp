#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    using ll = long long;

    vector<ll> w(n), s(n), v(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> s[i] >> v[i];
    }

    vector<int> index(n);
    iota(index.begin(), index.end(), 0);

    sort(index.begin(), index.end(), [&](int i, int j) {
        return w[i] + s[i] < w[j] + s[j];
    });

    int W = 20001;

    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1));

    for (int i = 0; i < n; i++) {
        int k = index[i];

        for (int j = 1; j <= W; j++) {
            dp[i + 1][j] = max(dp[i + 1][j - 1], dp[i][j]);

            if (j - w[k] >= 0 && j - w[k] <= s[k]) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[k]] + v[k]);
            }
        }
    }

    cout << dp[n][W] << endl;
}
