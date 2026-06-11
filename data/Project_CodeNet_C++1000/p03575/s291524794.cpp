#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using Graph=vector<vector<int>>;

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

int Renketucount(int N,int A,UnionFind tree){
    int count=0;
    rep(i,N){
        if(tree.same(A,i)){
            count++;
        }
    }
    return count;
}

void make_UF(int M,int k,const vector<pair<int,int>>A,UnionFind &tree){
    rep(i,M){
        if(i!=k){
            tree.unite(A[i].first,A[i].second);
        }
    }
}

int main(){
    int N,M;cin>>N>>M;
    vector<pair<int,int>>HEN(M);
    int cnt=0;
    rep(i,M){
        int a,b;cin>>a>>b;
        a--;b--;
        HEN[i].first=a;
        HEN[i].second=b;
    }
    rep(k,M){
        UnionFind tree(N);
        make_UF(M,k,HEN,tree);
        if(N!=Renketucount(N,0,tree)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
