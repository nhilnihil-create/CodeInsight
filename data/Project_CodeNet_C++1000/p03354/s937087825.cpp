#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

struct UnionFind{
    
    vector<ll> par;
    
    UnionFind(ll N) : par(N){
        for(ll i = 0; i < N; i++) par.at(i) = i;
    }
    
    ll root(ll x){
        ll px = par.at(x);
        if(x == px) return x;
        return par.at(x) = root(px); 
    }
    
    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        par.at(rx) = ry;
    }
    
    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
    
};


int main(void){
    ll N, M;
    cin >> N >> M;
    
    vector<ll> p(N);
    for(ll i = 0; i < N; i++){
        cin >> p.at(i);
    }
    
    UnionFind num(N);
    
    ll tmpa, tmpb;
    for(ll i = 0; i < M; i++){
        cin >> tmpa >> tmpb;
        num.unite(tmpa-1, tmpb-1);
    }
    
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(num.same(p.at(i)-1, i)){
            ans++;
        }
    }
    printf("%lld\n", ans);
    
}