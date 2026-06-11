#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 1e6 + 100;
vector<int> g[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    vector<nagai> d(n);
    for (auto& x : d)
        cin >> x;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b)
            {
             return d[a] > d[b];
            });
    map<nagai, int> mp;
    for (int i = 0; i < n; ++i)
        mp[d[i]] = i;
    vector<int> sz(n, 1);
    vector<pair<int, int>> edg;
    vector<bool> used(n);
    ord.pop_back();
    for (int x : ord)
    {
        used[x] = true;
        nagai dp = d[x] + sz[x] - (n - sz[x]);
        if (!mp.count(dp) || used[mp[dp]])
        {
             cout << -1 << '\n';
             return 0;
        }
        edg.emplace_back(mp[dp], x);
        sz[mp[dp]] += sz[x];
    }
    for (auto& p : edg)
    {
        int x = p.first, y = p.second;
        g[x].push_back(y), g[y].push_back(x);
    }
    vector<nagai> d1(n, -1);
    d1[0] = 0;
    vector<int> q = {0};
    for (int i = 0; i < q.size(); ++i)
    {
         int x = q[i];
         for (int y : g[x])
             if (d1[y] == -1)
                 d1[y] = d1[x] + 1, q.emplace_back(y);
    }
    if (d[0] != accumulate(d1.begin(), d1.end(), 0LL))
    {
        cout << -1 << '\n';
        return 0;
    }
    for (auto& x : edg)
        cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	return 0;
}

