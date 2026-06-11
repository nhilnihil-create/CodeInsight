#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

struct unionfind {
    vector<int> par;
    vector<int> sizes;

    unionfind(int n) : par(n),sizes(n,1){
        rep(i,0,n) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x,int y){
        x = root(x);
        y = root(y);

        if(x == y) return;

        if(sizes[x] < sizes[y] ) swap(x,y);

        par[y] = x;
        sizes[x] += sizes[y];
        sizes[y] = 0;

        return;
    }

    bool same(int x,int y){
        return root(x) == root(y);
    }

    int size(int x){
        return sizes[root(x)];
    }
};

int main(){
    ll n,m;
    cin >> n >> m;
    unionfind uf(n);

    rep(i,0,m){
        ll x,y,z;
        cin >> x >> y >> z;
        uf.unite(x-1,y-1);
    }

    map<ll,bool> mapp;

    ll ans = 0;
    rep(i,0,n){
        if(mapp.count(uf.root(i)) == 0){
            ans++;
            mapp[uf.root(i)] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}


