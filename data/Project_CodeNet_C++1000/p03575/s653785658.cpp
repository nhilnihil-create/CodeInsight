#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)
vector<vector<int>> G;
vector<bool> seen;
vector<pair<int, int>> edge;
void dfs(int now, int parent, int except)
{
    seen[now] = true;
    // cout << "except: " << edge[except].first << " " << edge[except].second << endl;
    for (int child : G[now])
    {
        // cout << "next: " << now << " " << child << endl;
        if (now == edge[except].first && child == edge[except].second)
            continue;
        if (child == edge[except].first && now == edge[except].second)
            continue;
        if (seen[child])
            continue;
        if (child == parent)
            continue;
        dfs(child, now, except);
    }
    return;
}
int main()
{
    int n, m;
    cin >> n >> m;
    G.resize(n, vector<int>());
    repi(i, m, 0)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge.push_back({a, b});
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    seen.resize(n, false);

    repi(i, m, 0)
    {
        seen.assign(n, false);
        dfs(0, -1, i);
        // cout << i << " : ";
        repi(j, n, 0)
        {
            // cout << seen[j] << " ";
            if (!seen[j])
            {
                ans++;
                break;
            }
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}