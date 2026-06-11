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
    string cmp;
    cin >> cmp;
    vec<ll> dpt(n + 1), dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++, swap(dpt, dp))
        for (int j = 1; j <= i; dpt[j] = MOD(dpt[j] + dpt[j - 1]), j++)
            if (cmp[i - 2] == '<')
                dpt[j] = MOD(dp[j - 1] - dp[0]);
            else
                dpt[j] = MOD(dp[i - 1] - dp[j - 1]);
    cout << dp[n];
    return 0;
}