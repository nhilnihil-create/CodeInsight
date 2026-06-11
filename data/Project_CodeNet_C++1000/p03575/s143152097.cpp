#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli connectednum(vector<vector<lli>> &g){
    lli n = g.size();
    vector<lli> seen(n);
    lli ret = 0;
    function<void(int)> dfs = [&](lli x){
        if(seen[x]) return;
        seen[x] = true;
        rep(j, g[x].size()){
            dfs(g[x][j]);
        }
    };
    rep(i, n){
        if(!seen[i]){
            dfs(i);
            ret++;
        }
    }
    return ret;
}

lli n, m;

int main(void){
    cin >> n >> m;
    vector<vector<lli>> g(n);
    vector<pair<lli, lli>> e(m);
    rep(i, m){
        lli a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        e[i] = {a, b};
    }
    lli ans = 0;
    rep(i, m){
        lli a, b;
        a = e[i].first;
        b = e[i].second;
        g[a].erase(find(g[a].begin(), g[a].end(), b));
        g[b].erase(find(g[b].begin(), g[b].end(), a));
        if(connectednum(g) > 1) ans++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << ans << endl;
    return 0;
}
