#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
public:
    UnionFind(int n){
        par.resize(n);
        rank.resize(n);
        for (int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
    int root(int x){
        if(par[x]==x)return x;
        else return par[x]=root(par[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool merge(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(rank[x]<rank[y])swap(x,y);
        if(rank[x]==rank[y])++rank[x];
        par[y]=x;
        return true;
    }
};

int main(){
    ll n,m;
    cin>>n>>m;
    UnionFind uf(2*n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        --a,--b;
        uf.merge(a,b+n);
        uf.merge(a+n,b);
    }
    if(uf.issame(0,n)){
        cout<<n*(n-1)/2-m<<endl;
    }
    else{
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(uf.issame(0,i))++cnt;
        }
        cout<<cnt*(n-cnt)-m<<endl;
    }
}
