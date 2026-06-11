#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int num, vector<ll>& w, map<int, set<pair<int, ll>>>& mp, vector<bool>& bmp)
{
    if(bmp[num]) return;
    bmp[num] = true;
    set<pair<int, ll>> now = mp[num];
    for(auto itr = now.begin(); itr != now.end(); itr++)
    {
        if(bmp[itr->first]) continue;
        w[itr->first] += w[num] + itr->second;
        dfs(itr->first, w, mp, bmp);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    map<int, set<pair<int, ll>>> mp;
    for(int i=0; i<N-1; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        mp[u].emplace(v, w);
        mp[v].emplace(u, w);
    }

    vector<ll> w(N, 0);
    vector<bool> bmp(N, false);
    for(int i=0; i<N; i++)
    {
        dfs(i, w, mp, bmp);
    }

    for(int i=0; i<N; i++)
    {
        // cout << i+1 << ' ' << w[i] << endl;
        if(w[i]%2) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}
