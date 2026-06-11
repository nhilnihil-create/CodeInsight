#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <math.h>
#include <assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

inline double nCr(const int n, int r)
{

    if (n == 0)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }
    if (r == 1)
    {
        return n;
    }
    if (n == r)
    {
        return 1;
    }

    if (r > n / 2)
    {
        r = n / 2;
    }

    double result = 1;
    for (double i = 1; i <= r; i++)
    {
        result *= (n - i + 1) / i;
    }

    return (result);
}

//----------------------------------------------------------------

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 2);
    a[0] = 0;
    vector<ll> ruiseki(n + 2);
    ruiseki[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        ruiseki[i] = ruiseki[i - 1] + abs(a[i - 1] - a[i]);
    }
    a[n + 1] = 0;
    ruiseki[n + 1] = ruiseki[n] + abs(a[n] - 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ruiseki[i - 1] + ruiseki[n + 1] - ruiseki[i + 1] + abs(a[i - 1] - a[i + 1]) << endl;
    }
}
