#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

const int MAX_N = 100005; // 要素数の最大

int par[MAX_N]; // 親
int rk[MAX_N];  // 木の深さ(rank)

// n要素で初期化
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rk[i] = 0;
    }
}

// 木の根を求める
int find(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    else
    {
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
    {
        return;
    }

    if (rk[x] < rk[y])
    {
        par[x] = y;
    }
    else
    {
        par[y] = x;
        if (rk[x] == rk[y])
        {
            rk[x]++;
        }
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        init(n);
        for (int j = 0; j < m; j++)
        {
            if (i != j)
            {
                unite(a[j], b[j]);
            }
        }
        bool flag = true;
        for (int j = 1; j < n && flag; j++)
        {
            if (!same(0, j))
            {
                flag = false;
            }
        }
        if (!flag)
        {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}