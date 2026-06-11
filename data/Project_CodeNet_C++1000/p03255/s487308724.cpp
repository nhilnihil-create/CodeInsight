#include <bits/stdc++.h>
#define show(x) std::cerr << #x << " = " << x << std::endl
using ll = long long;
int main()
{
    int N;
    ll X;
    std::cin >> N >> X;
    std::vector<ll> x(N), sum(N, 0);
    for (int i = 0; i < N; i++) { std::cin >> x[i], sum[i] = (i == 0 ? 0LL : sum[i - 1]) + x[i]; }
    auto cost = [](const int i) { return i == 1 ? 5 : 2 * i + 1; };
    auto get = [&](const int s, const int t) { return sum[t - 1] - (s == 0 ? 0 : sum[s - 1]); };
    ll ans = 1LL << 60;
    for (int i = 1; i <= N; i++) {
        const int n = (N + i - 1) / i;
        __int128_t sum = i * X;
        for (int j = 1; j <= n; j++) {
            const int s = std::max(0, N - i * j);
            const int t = N - i * (j - 1);
            sum += (__int128_t)get(s, t) * cost(j);
        }
        ans = std::min((__int128_t)ans, sum);
    }
    std::cout << ans + N * X << std::endl;

    return 0;
}
