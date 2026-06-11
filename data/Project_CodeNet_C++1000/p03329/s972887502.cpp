#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;
int main() {
    ll n;cin >> n;
    vector<ll>v;
    v.push_back(1);
    for(ll i=6;i<=n;i*=6){
        v.push_back(i);
    }
    for(ll i = 9; i <= n; i *= 9) {
        v.push_back(i);
    }
    vector<ll> cost(n+1,INF);
    cost[0]=0;
    for(ll j=0;j<v.size();j++){
    	for(ll i=0;i<n;i++){
            if(i+v[j]<=n)(cost[i+v[j]]=min(cost[i]+1,cost[i+v[j]]));
        }
    }
    cout << cost[n] << endl;
    return 0;
}
