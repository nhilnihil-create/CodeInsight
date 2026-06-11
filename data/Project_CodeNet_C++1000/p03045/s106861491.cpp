#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<bool> seen;

void dfs(vector<vector<int>> &G, int a){
    if(seen[a])return;
    seen[a] = true;
    for(int i: G[a]){
        dfs(G, i);
    }
    return;

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    seen.resize(n, false);
    int ans = 0;
    rep(i, n){
        if(seen[i]) continue;
        dfs(G, i);
        ans++;
    }
    cout << ans << endl;
    return 0;
}