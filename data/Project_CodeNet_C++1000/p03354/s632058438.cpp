#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

struct UnionFind{
    vector<int>parent;//親の番号
    UnionFind(int N):parent(N){
        rep(i,N){
            parent[i]=i;
        }
    }//全て根であるとして初期化
    int root(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=root(parent[x]);
    }//根を探す
    void unite(int x,int y){
        int rx=root(x);
        int ry=root(y);
        if(rx==ry){
            return;
        }
        parent[rx]=ry;
    }//xの根をyの根にくっつける
    bool same(int x,int y){
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }//x,yの属する木が同じならtrue
};

int main(){
    int N,M;cin>>N>>M;
    vector<int>p(N);
    rep(i,N){
        int a;cin>>a;a--;
        p.at(i)=a;
    }
    UnionFind tree(N);
    rep(i,M){
        int x,y;cin>>x>>y;
        x--;y--;
        tree.unite(x,y);
    }
    int count=0;
    rep(i,N){
        if(tree.same(i,p.at(i))){
            count++;
        }
    }
    cout<<count<<endl;
}