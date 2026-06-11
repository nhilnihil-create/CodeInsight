#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




//UnionFind Template
struct UnionFind{ //構造体の定義
    vector<int> d; 
    UnionFind(int n=0): d(n,-1) {} //コンストラクタ
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
    vector<int> a(m), b(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        a[i]--; b[i]--;
    }
    int cnt=0;
    rep(i,m){
        UnionFind uf(n);
        rep(j,m){
            if(i==j) continue;
            uf.unite(a[j], b[j]); 
        }
        if(uf.rootsize()>1){
            cnt++;
        }
    }
    cout<< cnt <<endl;
    return 0;


}