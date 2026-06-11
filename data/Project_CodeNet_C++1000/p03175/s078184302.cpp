#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

const int mod = 1000000007;
vector<int> g[100005];
pair<int, int> dfs(int u, int p)
{
    int allwhite = 1, anycolour = 1;
    for(auto &k: g[u])
        if(k != p)
        {
            pair<int, int> t = dfs(k, u);
            allwhite *= t.second;
            allwhite %= mod;
            anycolour *= (t.first+t.second)%mod;
            anycolour %= mod;
        }
    return {allwhite, anycolour};
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    pair<int, int> a = dfs(1, 1);
    cout << (a.first+a.second)%mod << endl;
}