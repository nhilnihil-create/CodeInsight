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
vector<vector<ll>> ruiseki;
vector<pair<ll, ll>> ichi(90010);
ll h, w, d;
void dfs(ll num, ll nv, ll cnt)
{
    if (nv + d > h * w)
    {
        return;
    }
    ruiseki[num][cnt + 1] = ruiseki[num][cnt] + llabs(ichi[nv].first - ichi[nv + d].first) + llabs(ichi[nv].second - ichi[nv + d].second);
    dfs(num, nv + d, cnt + 1);
}
int main()
{
    cin >> h >> w >> d;
    if (d <= 300)
    {
        ruiseki.resize(310);
        for (ll i = 0; i < ruiseki.size(); i++)
        {
            ruiseki[i].resize(90010);
        }
    }
    else
    {
        ruiseki.resize(90010);
        for (ll i = 0; i < ruiseki.size(); i++)
        {
            ruiseki[i].resize(310);
        }
    }
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            ll a;
            cin >> a;
            ichi[a] = make_pair(i + 1, j + 1);
        }
    }
    for (ll i = 1; i <= d; i++)
    {
        dfs(i, i, 0);
    }
    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll tmp_num = l % d;
        if (tmp_num == 0)
        {
            tmp_num = d;
        }
        ll tmp_l = l / d;
        if (l % d == 0)
        {
            tmp_l--;
        }
        ll tmp_r = r / d;
        if (r % d == 0)
        {
            tmp_r--;
        }
        cout << ruiseki[tmp_num][tmp_r] - ruiseki[tmp_num][tmp_l] << endl;
    }
}