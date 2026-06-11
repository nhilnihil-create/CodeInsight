#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <vector>

const int mod = 1e9 + 7;
const int kmax = 510000;

long long fact[kmax], fact_inv[kmax], inv[kmax];

int gcd(int a, int b)
{
    if (!b) {
        return a;
    }

    return gcd(b, a % b);
}

void init_comb()
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < kmax; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

long long comb(int n, int r)
{
    if (n < r) {
        return 0;
    }

    if (n < 0 || r < 0) {
        return 0;
    }

    return fact[n] * (fact_inv[r] * fact_inv[n - r] % mod) % mod;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }

    std::vector<int> num_matches = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    std::vector<int> dp_num(n + 1, 0);

    for (int i = 0; i < n; i++) {
        for (auto num : a) {
            if (i + num_matches[num] > n) {
                continue;
            }

            dp_num[i + num_matches[num]] = std::max(dp_num[i + num_matches[num]], dp_num[i] + 1);
        }
    }

    std::vector<std::string> dp(n + 1, "");

    for (auto num : a) {
        if (num_matches[num] > n) {
            continue;
        }

        dp[num_matches[num]] = std::max(dp[num_matches[num]], std::to_string(num));
    }

    for (int i = 0; i < n; i++) {
        if (dp[i] == "") {
            continue;
        }

        for (auto num : a) {
            if (i + num_matches[num] > n) {
                continue;
            }
            if (dp[i + num_matches[num]].length() <= dp[i].length()) {
                dp[i + num_matches[num]] = dp[i] + std::to_string(num);
            } else if (dp[i + num_matches[num]].length() == dp[i].length() + 1) {
                dp[i + num_matches[num]] = std::max(dp[i + num_matches[num]], dp[i] + std::to_string(num));
            }
        }
    }

    std::cout << dp[n] << std::endl;
}
