#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




//UnionFind Template
struct UnionFind{ //構造体の定義
    vector<int> d; //メンバ変数
    UnionFind(int n=0): d(n,-1) {} //コンストラクタ（構造体が呼ばれたときにすぐに実行される処理）
    int find(int x){
        if(d[x]<0) return x;
        return d[x]=find(d[x]);
    }
    bool unite(int x, int y){
        x=find(x); y=find(y);
        if(x==y) return false;
        if(d[x]<d[y]) swap(x,y);//d[x] is smaller. Then, connect d[x] to d[y].
        d[y]+=d[x];
        d[x]=y;
        return true;
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
    int size(int x){
        return -(d[find(x)]);   
    }
    int rootsize(){
        int cnt=0;
        for(auto& v: d){
            if(v<0) cnt++;
        }
        return cnt;
    }
};
//How to use
//UnionFind uf(n); などと書けば使えるようになる.ufというobjectが生成される
//uf.unite(a,b);などで中の関数を使える



int main(){
    int n,m; cin>>n>>m;
    vector<int> p(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    vector<int> x(m), y(m);
    rep(i,m) cin>>x[i]>>y[i];
    UnionFind uf(n);
    rep(i,m){
        x[i]--; y[i]--;
        uf.unite(x[i],y[i]);
    }
    int ans=0;
    rep(i,n){
        if(p[i]==i || uf.same(p[i],i)) ans++;
    }
    cout<<ans<<endl;
}