#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}


struct Union_Find{
    vector<int> par, depth;
    Union_Find(int n){init(n);}
    void init(int n){
        par.resize(n); depth.resize(n);
        for(int i=0; i<n; i++){
            par[i]=i;
            depth[i]=0;
        }
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x]=find(par[x]);
    }

    void unite(int x, int y){
        x=find(x), y=find(y);
        if(x == y) return;

        if(depth[x] < depth[y]) par[x]=y;
        else{
            par[y]=x;
            if(depth[x] == depth[y]) depth[x]++;
        }
    }

    bool same(int x, int y){
        return find(x) == find(y); 
    }
};


int main(){
    int N, M; cin >> N >> M;
    Union_Find uf(2*N);
    for(int i=0; i<M; i++){
        int x, y, z; cin >> x >> y >> z;
        x--, y--;
        if(z%2 == 0){
            uf.unite(x, y);
            uf.unite(x+N, y+N);
        }
        else{
            uf.unite(x, y+N);
            uf.unite(x+N, y);
        }
    }

    int ans=0;
    for(int i=0; i<N; i++){
        if(uf.par[i] == i) ans++;
    }
    cout <<ans << endl;
    return 0;
}