#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pi> island(m);
    for (int i = 0; i < m; i++)
    {
        cin >> island[i].first >> island[i].second;
    }

    sort(island.begin(), island.end(), [](pi a, pi b) { return a.first < b.first; });

    int cur = island[0].second;
    int ans = 1;
    for (int i = 0; i < m; i++)
    {
        if (cur <= island[i].first)
        {
            ans++;
            cur = island[i].second;
            continue;
        }

        cur = min(cur,island[i].second);
    }

    cout << ans << endl;
}