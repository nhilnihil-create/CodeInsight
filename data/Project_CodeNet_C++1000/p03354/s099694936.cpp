#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(){
    ll n, m;
    cin >> n >> m;
    vector<p> check;
    vector<vector<ll>> g(n+1);
    vector<ll> use(n+1, 1);
    ll len[n+1];
    ll ans = 0;
    for(ll i = 0; i < n; i++)
        cin >> len[i+1];
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        check.push_back(p(a,b));
        g[a].push_back(b);
        g[b].push_back(a);
        use[a] = -1; use[b] = -1;
    }
    ll sum = 0;
    ll dc = 0;
    for(ll i = 1; i <= n; i++){
        if(use[i]==1) continue;
        ans = 0;
        vector<ll> dist(n+1, -1);
        queue<ll> que;
        que.push(i);
        dist[i] = 0;
        ll count = 0;
        while(!que.empty()){
            ll v = que.front();
            que.pop();
            for(ll nv : g[v]){
                if(dist[nv]!=-1) continue;
                dist[nv] = dist[v]+1;
                que.push(nv);
               use[nv] = 1;
               count++;
            }
        }
        if(ans >= count) continue;
        for(ll i = 1; i <= n; i++){
            if(len[i]==i)
                ans++;
            else if(dist[i]==-1) continue;
            else if(len[i]!=i && dist[len[i]]!=-1)
                ans++;
        }
        sum = max(ans, sum);
    }
    cout << sum << endl;
    return 0;
}
