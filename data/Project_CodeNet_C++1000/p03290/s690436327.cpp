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
    ll d, g;
    cin >> d >> g;
    ll p[d];
    ll c[d];
    for (ll i = 0; i < d; i++)
    {
        cin >> p[i] >> c[i];
    }
    ll ans = infll;
    for (ll bit = 0; bit < (1 << d); bit++)
    {
        ll cnt = 0;
        ll sum = 0;
        ll rest = -100000000000;
        for (ll i = 0; i < d; i++)
        {
            if (bit & (1 << i))
            {
                cnt += p[i];
                sum += p[i] * (i + 1) * 100;
                sum += c[i];
            }
            else
            {
                chmax(rest, i);
            }
        }
        if (sum >= g)
        {
            chmin(ans, cnt);
        }
        else if (rest >= 0)
        {
            if (sum + p[rest] * (rest + 1) * 100 > g)
            {
                cnt += amarinasi(g - sum, (rest + 1) * 100);
                chmin(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}
