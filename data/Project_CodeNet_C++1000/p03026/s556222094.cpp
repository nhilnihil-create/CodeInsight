#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    vector<vector<ll>> g(n+1);
    vector<p> vp;
    for(ll i = 0; i < n-1; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        vp.push_back(p(a, b));
    }
    ll c[n+1];
    c[0] = 0;
    for(ll i = 1; i <= n; i++)
        cin >> c[i];
    sort(c, c+(n+1));
    vector<ll> dist(n+1, -1);
    queue<ll> que;
    que.push(1);
    dist[1] = 1;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
    vector<p> check;
    vector<ll> next(n+1);
    for(ll i = 1; i <= n; i++)
        check.push_back(p(dist[i], i));
    sort(check.begin(), check.end());
    for(ll i = 0; i < n; i++)
        next[check[i].second] = i+1;
    //for(ll i = 1; i <= n; i++)
      // cout << i << " " << next[i] << endl;
    ll ans = 0;
    ll sum[n+1];
    for(ll i = 0; i < n-1; i++){
        ll a = vp[i].first, b = vp[i].second;
        sum[a] = c[n-next[a]+1];
        sum[b] = c[n-next[b]+1];
        if(next[a]>next[b]){
            ans+=c[n-next[a]+1];
            //cout << c[n-next[a]+1] << endl;
        }
        if(next[a]<next[b]){
            ans+=c[n-next[b]+1];
            //cout << c[n-next[b]+1] << endl;
        }
    }
    cout << ans << endl;
    for(ll i = 1; i <= n; i++)
        cout << sum[i] << " ";
    cout << endl;
    return 0;
}
