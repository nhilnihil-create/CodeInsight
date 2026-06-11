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
    ll n;
    cin >> n;
    ll in_k;
    cin >> in_k;
    ll x[n];
    ll y[n];
    ll ans = 4000000000000000000;
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            for (ll k = j; k < n; k++)
            {
                for (ll l = k; l < n; l++)
                {
                    ll right = max({x[i], x[j], x[k], x[l]});
                    ll left = min({x[i], x[j], x[k], x[l]});
                    ll up = max({y[i], y[j], y[k], y[l]});
                    ll down = min({y[i], y[j], y[k], y[l]});
                    //cout << right << " " << left << " ; " << up << " " << down << " ";

                    ll cnt = 0;
                    for (ll m = 0; m < n; m++)
                    {
                        if (x[m] >= left && x[m] <= right)
                        {
                            if (y[m] >= down && y[m] <= up)
                            {
                                cnt++;
                            }
                        }
                    }
                    //cout << "; " << cnt << endl;
                    if (cnt >= in_k)
                    {
                        ll menseki = (right - left) * (up - down);
                        //cout << " ; " << menseki << endl;
                        if (menseki > 0)
                        {
                            chmin(ans, menseki);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
