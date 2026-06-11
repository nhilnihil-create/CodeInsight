#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr ll MOD = 998244353;

// a^b
template <typename T>
T mypow(T a, T b)
{
    if (b == 0)
        return 1;
    T tmp = mypow(a, b / 2);
    if (b % 2)
        return (((tmp * tmp) % MOD) * a) % MOD;
    else
        return (tmp * tmp) % MOD;
}

ll N, A, B, K;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> B >> K;
    ll res = 0;
    vector<ll> fact(N + 1, 1), inv(N + 1, 1);
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;

        inv[i] = mypow(fact[i], MOD - 2);
    }
    for (int i = 0; i <= N; i++)
    {
        ll x = i;
        if ((K - A * x) % B)
            continue;
        ll y = (K - A * x) / B;
        if (y < 0 || N < y)
            continue;
        ll tmp = fact[N];
        tmp *= inv[x];
        tmp %= MOD;
        tmp *= inv[N - x];
        tmp %= MOD;

        tmp *= fact[N];
        tmp %= MOD;
        tmp *= inv[y];
        tmp %= MOD;
        tmp *= inv[N - y];
        tmp %= MOD;

        res += tmp;
        res %= MOD;
    }
    cout << res << endl;
}
