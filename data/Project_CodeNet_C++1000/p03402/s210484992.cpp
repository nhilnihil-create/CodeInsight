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
const double pi = 3.14159265358979323846264;
//----------------------------------------------------------------

ll n, m;
vector<ll> go_seen(110, infll), back_seen(110, infll);
//ダイクストラ法
struct edge
{
    ll to, cost;
};
typedef pair<ll, ll> P;
struct graph
{
    ll V;
    vector<vector<edge>> G;
    vector<ll> d;

    graph(ll n)
    {
        init(n);
    }

    void init(ll n)
    {
        V = n;
        G.resize(V);
        d.resize(V);
        for (ll i = 0; i < V; i++)
        {
            d[i] = INF;
        }
    }

    void add_edge(ll s, ll t, ll cost)
    {
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s)
    {
        for (ll i = 0; i < n; i++)
        {
            go_seen[i] = infll;
            back_seen[i] = infll;
        }
        for (ll i = 0; i < V; i++)
        {
            d[i] = INF;
        }
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push(P(0, s));
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            ll v = p.second;
            if (d[v] < p.first)
                continue;
            for (auto e : G[v])
            {
                if (d[e.to] > d[v] + e.cost)
                {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                    go_seen[v] = e.to;
                    back_seen[e.to] = v;
                }
            }
        }
    }
};

int main()
{
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    ll cnt = 0;
    cout << 62 << " " << 100 << endl;
    for (ll i = 0; i < 30; i++)
    {
        for (ll j = 0; j < 100; j++)
        {
            if (i % 2)
            {
                cout << "#";
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    cout << "#";
                }
                else
                {
                    if (a > 0)
                    {
                        cout << ".";
                        a--;
                    }
                    else
                    {
                        cout << "#";
                    }
                }
                cnt++;
            }
        }
        cout << endl;
    }
    for (ll i = 0; i < 100; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (ll i = 0; i < 100; i++)
    {
        cout << ".";
    }
    cout << endl;
    cnt = 0;
    for (ll i = 0; i < 30; i++)
    {
        for (ll j = 0; j < 100; j++)
        {
            if (i % 2)
            {
                cout << ".";
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    cout << ".";
                }
                else
                {
                    if (b > 0)
                    {
                        cout << "#";
                        b--;
                    }
                    else
                    {
                        cout << ".";
                    }
                }
                cnt++;
            }
        }
        cout << endl;
    }
}
