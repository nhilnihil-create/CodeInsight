#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

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

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(10, vector<int>(10, 0)); // 隣接行列
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> c[i][j];
        }
    }
    int list[h * w];
    for (int i = 0; i < h * w; i++)
    {
        cin >> list[i];
    }

    // ワーシャルフロイド
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    int ans = 0;
    for (auto l : list)
    {
        if (l == -1)
        {
            continue;
        }
        ans += c[l][1];
    }
    cout << ans << endl;
    return 0;
}