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
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;
constexpr double PI = 3.14159265358979323846;
constexpr int dx[] = {0, 0, 1, -1};
constexpr int dy[] = {1, -1, 0, 0};

ll fastPow(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastPow(x * x % MOD, n / 2);
    else
        return x * fastPow(x, n - 1) % MOD;
}

ll fac[312345];
void combInit(int mx)
{
    fac[0] = 0;
    fac[1] = 1;
    for (int i = 2; i <= mx; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll modDiv(ll a, ll b)
{
    return a * fastPow(b, MOD - 2) % MOD;
}

ll comb(ll a, ll b)
{
    if (a < b)
        return 0;
    if (a <= 0 || b < 0)
        return 0;
    if (a == b)
        return 1;

    ll p, c;

    c = modDiv(fac[a], fac[a - b]);
    p = fac[b];

    ll res = modDiv(c, p);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    combInit(312345);

    ll n, a, b, k;
    vector<pair<ll, ll>> v;

    cin >> n >> a >> b >> k;

    if (k == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    for (ll i = 1; i <= n; i++)
    {
        ll j = k - a * i;

        if (j < 0)
            break;

        if (j % b)
            continue;

        if (j / b > n)
            continue;

        v.push_back(make_pair(i, j / b));
    }

    ll res = 0;

    for (pair<ll, ll> p : v)
    {
        res += comb(n, p.first) * comb(n, p.second) % MOD;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}