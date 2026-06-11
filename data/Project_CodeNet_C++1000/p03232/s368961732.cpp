#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr ll MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> inv(100010, 1), sum(100010, 1);
    for (ll i = 2; i <= 100000; i++)
    {
        inv[i] = mypow(i, MOD - 2);
        sum[i] = (sum[i - 1] + inv[i]) % MOD;
    }
    int N;
    cin >> N;
    ll res = 0;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        ll p = (sum[N - i] + sum[i + 1] + MOD - 1) % MOD;
        res += A[i] * p;
        res %= MOD;
    }
    for (int i = 0; i < N; i++)
    {
        res *= (i + 1);
        res %= MOD;
    }
    cout << res << endl;
}
