#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N){
        rep(i,N)par[i]=i;
    }

    int root(int x){
        if(par[x]==x)return x;
        return par[x]=root(par[x]);
    }

    void unite(int x, int y){
        if(root(x)==root(y))return;
        par[root(x)]=root(y);
    }

    bool same(int x, int y){
        return root(x)==root(y);
    }
};

int main(){
    int N,M;
    cin>>N>>M;
    int p[N];
    rep(i,N)cin>>p[i];
    UnionFind tree(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        tree.unite(a-1,b-1);
    }
    int ans=0;
    rep(i,N){
        if(tree.same(i,p[i]-1))ans++;
    }
    cout<<ans<<endl;
    return 0;
}