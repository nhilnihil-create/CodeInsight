// https://atcoder.jp/contests/dp/submissions/8562895
// By mcalancea
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<vector<int>> a(n, vector<int> (n, 0));

    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1)
            cin >> a[i][j];

    vector<int64_t> value((1 << n), 0);

    for (int mask = 0; mask < (1 << n); mask += 1) {
        vector<int> rabbits;
        for (int i = 0; i < n; i += 1)
            if ((1 << i) & mask)
                rabbits.push_back(i);

        int k = rabbits.size();
        for (int i = 0; i < k; i += 1)
            for (int j = i + 1; j < k; j += 1)
                value[mask] += a[rabbits[i]][rabbits[j]];
    }

    vector<int64_t> dp((1 << n), 0);

    for (int mask = 0; mask < (1 << n); mask += 1) {
        dp[mask] = value[mask];
        for (int sub = mask; sub > 0; sub = (sub - 1) & mask)
            dp[mask] = max(dp[mask], dp[sub] + dp[mask ^ sub]);
    }

    cout << dp[(1 << n) - 1] << "\n";
}
