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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) // 各辺を除外したケースを計算する
    {
        vector<vector<int>> G(n);
        rep(j, m)
        {
            if (j == i)
            {
                continue;
            }
            G[a[j]].push_back(b[j]);
            G[b[j]].push_back(a[j]);
        }
        queue<int> qe;
        qe.push(0);
        vector<bool> seen(n, false);
        while (!qe.empty())
        {
            int now = qe.front();
            qe.pop();
            if (seen[now])
            {
                continue;
            }
            for (int next : G[now])
            {
                if (!seen[next])
                {
                    qe.push(next);
                }
            }
            seen[now] = true;
        }
        for (bool s : seen)
        {
            if (!s)
            {
                ++ans;
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
