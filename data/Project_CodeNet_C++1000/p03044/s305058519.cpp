#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    map<P,int> w;
    rep(i,n-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        w[P(a,b)] = c;
        w[P(b,a)] = c;
    }

    vector<ll> dist(n, -1);
    queue<int> que;
    
    dist[0] = 0;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(auto nv : g[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + w[P(v,nv)];
            que.push(nv);
        }
    }

    rep(i,n){
        if(dist[i] % 2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
}