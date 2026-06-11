#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());
using ll = long long;
using P = pair<int, int>;

struct Sieve
{
    int n;
    vector<int> f, primes;
    Sieve(int n = 1) : n(n), f(n + 1)
    {
        f[0] = f[1] = -1;
        for (ll i = 2; i <= n; ++i)
        {
            if (f[i])
                continue;
            primes.push_back(i);
            f[i] = i;
            for (ll j = i * i; j <= n; j += i)
            {
                if (!f[j])
                    f[j] = i;
            }
        }
    }
    bool isPrime(int x) { return f[x] == x; }
    vector<int> factorList(int x)
    {
        vector<int> res;
        while (x != 1)
        {
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }
    vector<P> factor(int x)
    {
        vector<int> fl = factorList(x);
        if (fl.size() == 0)
            return {};
        vector<P> res(1, P(fl[0], 0));
        for (int p : fl)
        {
            if (res.back().first == p)
            {
                res.back().second++;
            }
            else
            {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};

int choose2(int n)
{
    return n * (n - 1) / 2;
}

int main()
{
    int N, K;
    cin >> N;
    Sieve sieve(N);
    vector<int> factors(100);
    rep(i, N)
    {
        int n = i + 1;
        vector<pair<int, int>> factor = sieve.factor(n);
        rep(j, factor.size())
        {
            factors[factor[j].first] += factor[j].second;
        }
    }

    int ans = 0;
    int n2 = 0, n4 = 0, n14 = 0, n24 = 0, n74 = 0;
    rep(j, 100)
    {
        if (factors[j] >= 2)
            n2++;

        if (factors[j] >= 4)
            n4++;

        if (factors[j] >= 14)
            n14++;

        if (factors[j] >= 24)
            n24++;

        if (factors[j] >= 74)
            n74++;
    }
    ans += (n2 - 2) * choose2(n4);
    ans += (n2 - 1) * n24;
    ans += (n4 - 1) * n14;
    ans += n74;

    cout << ans << endl;
    return 0;
}