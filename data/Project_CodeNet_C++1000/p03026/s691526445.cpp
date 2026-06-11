#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<vector<ll>> graph(n);
    for(i = 0;i < n-1;++i){
        ll a,b;
        cin >> a >> b;
        --a;    --b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    vector<ll> c(n);
    for(i = 0;i < n;++i){
        cin >> c.at(i);
    }
    sort(all(c), greater<ll>());
    ll ans = 0;
    
    queue<ll> que;
    vector<ll> vdis(n,-1);
    ll top = 0;
    vdis.at(top) = 0;
    que.emplace(top);
    ll nc = 0;
    vdis.at(nc) = c.at(nc);
    while(!que.empty()){
        ll now = que.front();
        que.pop();
        for(i = 0;i < graph.at(now).size();++i){
            ll next = graph.at(now).at(i);
            if(vdis.at(next) == -1){
                ++nc;
                vdis.at(next) = c.at(nc);
                ans += c.at(nc);
                que.emplace(next);
            }
        }
    }
    cout << ans << endl;
    for(i = 0;i < n;++i){
        cout << vdis.at(i) << endl;
    }
    return 0;
}