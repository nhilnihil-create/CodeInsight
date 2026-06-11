#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);

const int MAX=200010;


struct UnionFind {
    vector<int> par;
    vector<int> siz;
    UnionFind(int N) : par(N), siz(N, 1) {
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    bool issame(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return siz[root(x)];
    }
};


int main() {
    ios_base::sync_with_stdio(false); 

    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> p(m);
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        p[i]={a-1,b-1};
    }
    ll cnt=n*(n-1)/2;
    vector<ll> ans(m);
    UnionFind tree(n);
    invrep(i,m) {
        ans[i]=cnt;
        ll s1=tree.size(p[i].first),s2=tree.size(p[i].second);
        if (!tree.issame(p[i].first,p[i].second)) {
            cnt-=s1*s2;
            tree.unite(p[i].first,p[i].second);
        }
    }
    rep(i,m) cout << ans[i] << endl;

    return 0;
}
