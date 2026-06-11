#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <numeric>
#include <iomanip>
#define ll long long
#define pi 3.14159265358979323846
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};
/*
 vector<vector<ll>> g(n+1);
    for(ll i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dist(n+1, -1);
    queue<ll> que;
    que.push(1);
    dist[1] = 0;
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        for(ll nv : g[v]){
            if(dist[nv]!=-1) continue;
            dist[nv] = dist[v]+1;
            que.push(nv);
        }
    }
*/

int main(){
    ll n;
    cin >> n;
    map<ll, ll> a{}, b{};
    for(ll i = 0; i < n; i++){
        ll c;
        cin >> c;
        if(i%2==0) a[c]++;
        else b[c]++;
    }
    vector<p> va, vb;
    va.push_back(p(0, -1));
    vb.push_back(p(0, -1));
    for(auto &z : a){
        ll x = z.first, y = z.second;
        va.push_back(p(y, x));
    }
    sort(va.begin(), va.end());
    for(auto &z : b){
        ll x = z.first, y = z.second;
        vb.push_back(p(y, x));
    }
    sort(vb.begin(), vb.end());
    ll ans = 0;
    if(va[va.size()-1].second!=vb[vb.size()-1].second)
        ans = (n/2-va[va.size()-1].first)+(n/2-vb[vb.size()-1].first);

    else if(va[va.size()-1].second==vb[vb.size()-1].second){
        ll x = (n/2-va[va.size()-1].first)+(n/2-vb[vb.size()-2].first);
        ll y = (n/2-vb[vb.size()-1].first)+(n/2-va[va.size()-2].first);
        ans = min(x, y);
    }
    cout << ans << endl;
    return 0;
}
