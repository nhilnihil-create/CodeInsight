#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

const int MAX_N = 100100; // 要素数の最大

ll par[MAX_N]; // 親
ll siz[MAX_N]; // 木のサイズ

// n要素で初期化
void init(int n)
{
    for (int i = 0; i < n; ++i)
    {
        par[i] = i;
        siz[i] = 1;
    }
}

// 木の根を求める
int find(int x)
{
    while (par[x] != x)
        x = par[x] = par[par[x]];
    return x;
}

// xとyの属する集合を併合
bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;

    if (siz[x] < siz[y])
        swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    return true;
}

// 連結判定
bool same(int x, int y)
{
    return find(x) == find(y);
}

ll size(int x)
{
    return siz[find(x)];
}

int main()
{
    ll n, m;
    cin >> n >> m;
    init(n);
    vector<P> bridge(m);
    for (int i = 0; i < m; i++)
    {
        cin >> bridge[i].first >> bridge[i].second;
        --bridge[i].first;
        --bridge[i].second;
    }
    reverse(bridge.begin(), bridge.end());
    stack<ll> ans; // 答えを格納する
    ll total = n * (n - 1) / 2;
    for (int i = 0; i < m; i++)
    {
        ans.push(total);

        int a = bridge[i].first;
        int b = bridge[i].second;
        if (!same(a, b))
        {
            total -= size(a) * size(b);
            unite(a, b);
        }
    }
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}
