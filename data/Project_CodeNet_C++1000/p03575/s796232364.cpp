#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
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
    vector<pair<int,int>> G(M);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        G[i].first=a-1;
        G[i].second=b-1;
    }
    int ans=0;
    rep(i,M){
        UnionFind tree(N);
        rep(j,M){
            if(j!=i)tree.unite(G[j].first,G[j].second);
        }
        if(!(tree.same(G[i].first,G[i].second)))ans++;
    }
    cout<<ans<<endl;
    return 0;
}