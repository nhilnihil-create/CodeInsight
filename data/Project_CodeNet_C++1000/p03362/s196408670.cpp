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

//素数列挙longlong型配列
std::vector<ll> sosuurekkyo(ll max)
{
    vector<bool> tmp;
    vector<ll> ret;
    if (max + 1 > tmp.size())
    {                              // resizeで要素数が減らないように
        tmp.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    }
    tmp[0] = false; // 0は素数ではない
    tmp[1] = false; // 1は素数ではない

    for (ll i = 2; i * i <= max; ++i)
    { // 0からsqrt(max)まで調べる
        if (tmp[i])
        { // iが素数ならば
            for (ll j = 2; i * j <= max; ++j)
            {                       // (max以下の)iの倍数は
                tmp[i * j] = false; // 素数ではない
            }
        }
    }
    for (ll i = 0; i <= max; i++)
    {
        if (tmp[i])
        {
            ret.push_back(i);
        }
    }
    return (ret);
}

int main()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    for (auto f : sosuurekkyo(5000000))
    {
        if (f == 2)
        {
            continue;
        }
        if (f % 5 != 1)
        {
            continue;
        }
        cout << f << " ";
        cnt++;
        if (cnt == n)
        {
            break;
        }
    }
    cout << endl;
}