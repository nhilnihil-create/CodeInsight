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
const double pi = 3.14159265358979323846264;

int main()
{
    ll n, c;
    cin >> n >> c;
    ll d[c][c];
    ll a[n][n];
    map<ll, ll> rensou0, rensou1, rensou2;
    for (ll i = 0; i < c; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            cin >> d[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if ((i + j) % 3 == 0)
            {
                rensou0[a[i][j] - 1]++;
            }
            else if ((i + j) % 3 == 1)
            {
                rensou1[a[i][j] - 1]++;
            }
            else
            {
                rensou2[a[i][j] - 1]++;
            }
        }
    }
    ll sum = infll;
    for (ll i = 0; i < c; i++)
    {
        for (ll j = 0; j < c; j++)
        {
            for (ll k = 0; k < c; k++)
            {
                if (j == k || i == k || i == j)
                {
                    continue;
                }
                ll tmp = 0;
                for (auto f : rensou0)
                {
                    tmp += d[f.first][i] * f.second;
                }
                for (auto f : rensou1)
                {
                    tmp += d[f.first][j] * f.second;
                }
                for (auto f : rensou2)
                {
                    tmp += d[f.first][k] * f.second;
                }
                chmin(sum, tmp);
            }
        }
    }
    cout << sum << endl;
    return 0;
}