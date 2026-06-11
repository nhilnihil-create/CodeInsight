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
    ll n, m;
    cin >> n >> m;
    ll x[n];
    ll y[n];
    ll z[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    ll a[n];
    ll b[n];
    ll c[n];
    ll d[n];
    ll e[n];
    ll f[n];
    ll g[n];
    ll h[n];
    for (ll i = 0; i < n; i++)
    {
        a[i] = x[i] + y[i] + z[i];
        b[i] = x[i] + y[i] - z[i];
        c[i] = x[i] - y[i] + z[i];
        d[i] = x[i] - y[i] - z[i];
        e[i] = -x[i] + y[i] + z[i];
        f[i] = -x[i] + y[i] - z[i];
        g[i] = -x[i] - y[i] + z[i];
        h[i] = -x[i] - y[i] - z[i];
    }
    sort(a, a + n, greater<ll>());
    sort(b, b + n, greater<ll>());
    sort(c, c + n, greater<ll>());
    sort(d, d + n, greater<ll>());
    sort(e, e + n, greater<ll>());
    sort(f, f + n, greater<ll>());
    sort(g, g + n, greater<ll>());
    sort(h, h + n, greater<ll>());
    ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0, ans7 = 0, ans8 = 0;
    for (ll i = 0; i < m; i++)
    {
        ans1 += a[i];
        ans2 += b[i];
        ans3 += c[i];
        ans4 += d[i];
        ans5 += e[i];
        ans6 += f[i];
        ans7 += g[i];
        ans8 += h[i];
    }
    cout << max({ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8}) << endl;
}
