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
//UnionFind木
struct UnionFind
{
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> siz;
    UnionFind(ll N) : par(N), siz(N)
    { //最初は全てが根であるとして初期化
        for (ll i = 0; i < N; i++)
        {
            par[i] = i;
            siz[i] = 1;
        }
    }

    ll root(ll x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y)
    {                    // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry)
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        if (siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
        return; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    ll size(ll x)
    { // 素集合のサイズ
        return siz[root(x)];
    }

    bool same(ll x, ll y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n);
    ll p[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        uf.unite(x - 1, y - 1);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (uf.same(i, p[i] - 1))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}