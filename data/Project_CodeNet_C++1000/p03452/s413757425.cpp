#include "bits/stdc++.h"
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define put(a) cout<<a<<"\n"
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

template<typename W>
class WeightedUnionFind{
private:
    vector<int> par,height,size;
    vector<W> dif_w;
public:
    WeightedUnionFind(int n,W unit=0){
        par.resize(n);
        REP(i,n){
            par[i] = i;
        }
        height.resize(n,0);
        size.resize(n,1);
        dif_w.resize(n,unit);
    }
    int root(int x){
        if(par[x]==x){
            return x;
        }else{
            int r = root(par[x]);
            dif_w[x] += dif_w[par[x]];
            return par[x] = r;
        }
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
    bool unite(int x,int y,W w){
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if(x==y)return false;
        if(height[x]<height[y]){
            par[x]=y;
            size[y]+=size[x];
            dif_w[x] = -w;
        }else{
            par[y]=x;
            size[x]+=size[y];
            dif_w[y] = w;
            if(height[x]==height[y])height[x]++;
        }
        return true;
    }
    int cnt(int x){
        x=root(x);
        return size[x];
    }
    W weight(int x){
        root(x);
        return dif_w[x];
    }
    W dif(int x,int y){//y-x
        return weight(y)-weight(x);
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    WeightedUnionFind<int> uf(n);
    REP(i,m){
        int l,r,d;
        cin >> l >> r >> d;
        l--;r--;
        if(uf.same(l,r)){
            int dif = uf.dif(l,r);
            if(d!=dif){
                put("No");
                return 0;
            }
        }else{
            uf.unite(l,r,d);
        }
    }
    put("Yes");
    return 0;
}
