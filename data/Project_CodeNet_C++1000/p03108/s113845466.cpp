#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

#define MAX_N 1

typedef long long ll;

const double PI = 3.141592653589793;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

struct UnionFind{
    vector<ll> parent;
    vector<ll> sizes;
    ll N;
    UnionFind(ll n){
        parent.resize(n);
        sizes.resize(n);
        N =  n;
        for(ll i = 0; i < n; i++){
            parent[i] = i;
            sizes[i] = 1;
        }
    }

    ll root(ll s){
        if(parent[s] == s) return s;
        return root(parent[s]);
    }

    bool same(ll s,ll t){
        ll rs = root(s);
        ll rt = root(t);
        if(rs == rt) return true;
        else return false; 
    }

    void integrate(ll s,ll t){
        ll rs = root(s);
        ll rt = root(t);
        if(rs == rt) return;
        if(sizes[rs] >= sizes[rt]){
            parent[rt] = rs;
            sizes[rs] += sizes[rt];
        }
        else{
            parent[rs] = rt;
            sizes[rt] += sizes[rs];
        }
    }

    ll renketu(ll s){
        ll rs = root(s);
        return sizes[rs];
    }
};

int main(){
    ll n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<ll,ll>> road(m);
    for(ll i = 0; i < m;i++){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        road[i] = make_pair(a,b);
    }
    ll a = (n * n - n) / 2;
    ll pre = 0;
    ll ans[m+1];
    ans[m] = a;
    for(int i = m-1; i >= 0; --i){
        ll x = road[i].first;
        ll y = road[i].second;
        if(uf.same(x,y)){
            ans[i] = a - pre;
            continue;
        }
        pre += uf.renketu(x) * uf.renketu(y);
        ans[i] = a - pre;
        uf.integrate(x,y);
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << endl;
    }
    return 0;
}