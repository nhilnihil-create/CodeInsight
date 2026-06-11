#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


// union-find
struct UnionFind{
    vector<ll> d;
    UnionFind(ll n): d(n,-1){}

    ll root (ll x){
        if(d[x] < 0) return x; // 自分が根
        return d[x] = root(d[x]);
    }

    bool unite(ll x, ll y){
        x = root(x); y = root(y);
        if(x == y)return false;
        if(d[x]>d[y])swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(ll x, ll y){ //同じグループか判定
        return root(x) == root(y);
    }

    ll size(ll x){
        return -d[root(x)];
    }
};

int main(){

    ll n,m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m){
        ll x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        if(!uf.same(x,y)){
            uf.unite(x,y);
        }
    }

    map<ll,ll> mp;
    rep(i,n){
        mp[uf.root(i)]++;
    }

    ll ans = 0;
    for(auto it:mp){
        ans ++;
    }

    cout << ans << endl;



    return 0;
}