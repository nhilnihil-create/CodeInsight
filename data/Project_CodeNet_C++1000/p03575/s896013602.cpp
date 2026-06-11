#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

struct UnionFind{
    vector<long long> par;
    vector<long long> siz;
    //Constractor
    UnionFind(long long sz_) : par(sz_),siz(sz_,1LL){
        for(long long i = 0;i < sz_;i++)par[i] = i;
    }
    void init(long long sz_){
        par.resize(sz_);
        siz.resize(sz_);
        for(long long i = 0;i < sz_;i++)par[i] = i;
    }
    //MemberFunc
    long long find(long long x){
        while(par[x] != x)x = par[x] = par[par[x]];
        return x;
    }
    void unite(long long x, long long y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        if(siz[x] < siz[y])swap(x,y);
        siz[x] += siz[y];
        par[y] = x;
    }
    bool same(long long x, long long y){
        return find(x) == find(y);
    }
    long long size(long long x){
        return siz[find(x)];
    }
};

//ミョ(-ω- ?)
int main() {
    int n,m;
    cin >> n >> m;
    vector<P> v(m);
    rep(i,m){
        cin >> v[i].first >> v[i].second;
        --v[i].first;
        --v[i].second;
    }
    int res = 0;
    rep(i,m){
        UnionFind uf(n);
        rep(j,m){
            if(i != j)uf.unite(v[j].first,v[j].second);
        }
        rep(j,n){
            bool b = 0;
            rep(k,n){
                if(j == k)continue;
                if(!uf.same(j,k)){
                    b = true;
                    break;
                }
            }
            if(b){
                res++;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}