#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

struct union_find{
    vector<ll> par;
    vector<ll> rank;
    vector<ll> siz;
    
    union_find(ll N) : par(N), rank(N), siz(N){
        rep(i,N){
            par[i] = i;
            rank[i] = 0;
            siz[i] = 1;
        }
    }
    
    ll root(ll x){
        if (par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }
    
    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]){
            par[rx] = ry;
            siz[ry] += siz[rx];
        }
        else{
            par[ry] = rx;
            siz[rx] += siz[ry];
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
    
    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
    
    ll size(ll x){
        return siz[root(x)];
    }
};

int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll> > vec(M);
    rep(i,M){
        cin >> vec[i].first >> vec[i].second;
        vec[i].first--;
        vec[i].second--;
    }
    union_find tree(N);
    vector<ll> ans(M);
    ll unconvenience = N * (N - 1) / 2;
    ans[M - 1] = unconvenience;
    for (ll i = M - 1; i >= 1; i--){
        if (tree.same(vec[i].first, vec[i].second)){
            ans[i - 1] = unconvenience;
        }
        else{
            unconvenience -= tree.size(vec[i].first) * tree.size(vec[i].second);
            ans[i - 1] = unconvenience;
            tree.unite(vec[i].first, vec[i].second);
        }
    }
    rep(i,M){
        cout << ans[i] << endl;
    }
}