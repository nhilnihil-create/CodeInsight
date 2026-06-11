#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, m; cin >> n >> m;
    vector<P> edge;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b; cin >> a >> b;
        --a, --b;
        edge.push_back(make_pair(a,b));
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    rep(i,m){
        P deleted = edge[i];
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto nv : G[v]){
                if(v == deleted.first && nv == deleted.second) continue;
                if(nv == deleted.first && v == deleted.second) continue;
                if(dist[nv] != -1) continue;
                q.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
        bool isBridge = false;
        rep(i,n){
            if(dist[i] == -1) isBridge = true;
        }
        if(isBridge) {
            //cout << deleted.first << " " << deleted.second << endl;
            ans++;
        }
    }
    cout << ans << endl;
}