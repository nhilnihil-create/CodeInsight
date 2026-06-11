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

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> G(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        G[r][l]++;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j + 1] += G[i][j];
        }
    }
    for (int j = 0; j < n + 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            G[i + 1][j] += G[i][j];
        }
    }
    // for (auto g : G)
    // {
    //     print(g);
    // }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << G[b][b] - G[b][a - 1] << endl;
    }
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