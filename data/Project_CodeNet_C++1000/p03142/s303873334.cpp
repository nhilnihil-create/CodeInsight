#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> G(n + 1);
    vector<ll> deg_in(n + 1);
    ll i, j, k;
    for(i = 0; i < n -1 + m;i++){
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        deg_in[b]++;
    }
    ll root = -1;
    for(i = 1; i <= n; i++) {
        if(deg_in[i]==0){
            root = i;
            break;
        }
    }
    vector<ll> parent(n + 1,-1);
    parent[root] = 0;
    queue<ll> que;
    que.push(root);
    while(!que.empty()){
        ll now = que.front();
        que.pop();
        for(ll x:G[now]){
            deg_in[x]--;
            if(deg_in[x]==0){
                parent[x] = now;
                que.push(x);
            }
        }
    }

    for(i = 1; i <= n;i++){
        cout << parent[i] << endl;
    }
    return 0;
}