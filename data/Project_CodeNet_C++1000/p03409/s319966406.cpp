#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> rs(n), bs(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        rs[i].second = x;
        rs[i].first = y;
    }
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        bs[i].first = x;
        bs[i].second = y;
    }
    sort(rs.begin(), rs.end());
    sort(bs.begin(), bs.end());
    reverse(rs.begin(), rs.end());
    vector<bool> used(n, false); // 赤の点が使用済みかを保存する

    int ans = 0;
    for (int i = 0; i < n; i++) // 青の点を順番に走査
    {
        for (int j = 0; j < n; j++) // 赤の点を順番に走査
        {
            if (!used[j] && bs[i].first > rs[j].second && bs[i].second > rs[j].first)
            {
                used[j] = true;
                ans++;
                break;
            }
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
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
