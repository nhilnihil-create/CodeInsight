#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

ll fastPow(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastPow(x * x % MOD, n / 2);
    else
        return x * fastPow(x, n - 1) % MOD;
}

ll modDiv(ll a, ll b)
{
    return a * fastPow(b, MOD - 2) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll all, res, p[112345];
    cin >> n;

    all = 1;
    REP(i, n)
    {
        all *= (i + 1);
        all %= MOD;
    }

    p[0] = 0;
    p[1] = 1;
    REP(i, n + 10)
    {
        p[i + 2] = p[i + 1] + modDiv(1, i + 2);
        p[i + 2] %= MOD;
    }

    res = 0;

    REP(i, n)
    {
        ll a;
        cin >> a;

        res += (all * a) % MOD * (p[n - (i + 1) + 1] + p[(i + 1)] - 1);
        res %= MOD;
    }

    //res *= all;
    res %= MOD;

    cout << res << endl;

    return 0;
}