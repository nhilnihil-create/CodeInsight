#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

struct UnionFind{
    
    vector<ll> par;
    vector<ll> trsize; //それを根とする木の大きさ
    
    UnionFind(ll N) : par(N), trsize(N){
        for(ll i = 0; i < N; i++) par.at(i) = i;
        for(ll i = 0; i < N; i++) trsize.at(i) = 1;
    }
    
    ll root(ll x){
        if(x == par.at(x)) return x;
        return par.at(x) = root(par.at(x));
    }
    
    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        par.at(rx) = ry;
        trsize.at(ry) = trsize.at(rx) + trsize.at(ry);
    }

    ll size(ll x){
        return trsize.at(root(x));
    }
    
    bool same(ll x, ll y){
        if(root(x) == root(y)) return true;
        return false;
    }
    
};

int main(void){
    ll N,M;
    cin >> N >> M;
    
    vector<pair<ll,ll>> bridge(M);
    for(ll i = 0; i<M; i++){
        cin >> bridge.at(i).first >> bridge.at(i).second;
        bridge.at(i).first--;
        bridge.at(i).second--;
    }
    
    vector<ll> ans(M, 0);
    ans.at(M-1) = N*(N-1)/2;
    
    UnionFind islands(N);
    
    ll a,b;
    for(ll i = M-1; i > 0; i--){
        a = bridge.at(i).first;
        b = bridge.at(i).second;
        if(!islands.same(a,b)){
            ans.at(i-1) = ans.at(i) - islands.size(a) * islands.size(b);
            islands.unite(a, b);
        }
        else{
            ans.at(i-1) = ans.at(i);
        }
    }
    
    for(ll i = 0; i < M; i++){
        printf("%lld\n", ans.at(i));
    }
    
}