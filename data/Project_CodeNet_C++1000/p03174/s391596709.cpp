#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#define MOD(x) (x + 1000000007) % (1000000007)

using namespace std;

template <class t>
using vec = vector<t>;
using ll = long long;

const int MAX = numeric_limits<int>::max();

template <class t>
ostream &operator<<(ostream &out, vec<t> &v)
{
    for (auto &e : v)
        out << e << " ";
    out << "\n";
    return out;
}

template <class t>
istream &operator>>(istream &in, vec<t> &v)
{
    for (auto &e : v)
        in >> e;
    return in;
}

int main()
{
    int n;
    cin >> n;
    vec<vec<int>> can(n, vec<int>(n));
    cin >> can;
    vec<ll> dp(1 << n);
    dp[0] = 1;
    for (ll mask = 0; mask < (1 << n); mask++)
    {
        for (int b = 0; b < n; b++)
        {
            if (!(mask & (1 << b)))
            {
                int a = __builtin_popcountll(mask | (1 << b));
                if (can[a - 1][b])
                    dp[mask | (1 << b)] = MOD(dp[mask | (1 << b)] + dp[mask]);
            }
        }
    }
    cout << dp[(1 << n) - 1];
    return 0;
}