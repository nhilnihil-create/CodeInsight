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
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

inline bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

inline bool chmax(ll &a, ll b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}
//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------

int main()
{
    ll n, m, q;
    cin >> n >> m >> q;
    ll l, r;
    vector<vector<ll>> a(n, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++)
    {
        cin >> l >> r;
        a[l - 1][r - 1]++;
    }
    ll ruiseki[n + 1][n + 1];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ruiseki[i][j + 1] = ruiseki[i][j] + a[i][j];
        }
    }
    ll x, y;
    for (ll i = 0; i < q; i++)
    {
        cin >> x >> y;
        ll sum = 0;
        for (ll i = x - 1; i < y; i++)
        {
            sum += ruiseki[i][y] - ruiseki[i][x - 1];
        }
        cout << sum << endl;
    }
}
