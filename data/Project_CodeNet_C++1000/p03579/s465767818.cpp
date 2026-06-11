#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

struct UnionFind{
private:
    vector<int> data;
public:
    UnionFind(int n){
        data.assign(n,-1);
    }
    int root(int x){
        if(data[x]<0)return x;
        else return data[x]=root(data[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool merge(int x,int y){
        x=root(x),y=root(y);
        if(x==y)return false;
        if(data[x]>data[y])swap(x,y);
        data[x]+=data[y];
        data[y]=x;
        return true;
    }
    int size(int x){
        return -data[root(x)];
    }
};

int main(){
    ll n,m;
    cin>>n>>m;
    UnionFind uf(n+n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        --a,--b;
        uf.merge(a+n,b);
        uf.merge(a,b+n);
    }
    bool bi=true;
    rep(i,n){
        bi&=!uf.issame(i,i+n);
    }
    if(!bi){
        cout<<n*(n-1)/2-m<<endl;
        return 0;
    }
    int r=uf.root(0);
    ll ans=0;
    rep(i,n){
        if(r==uf.root(i))++ans;
    }
    cout<<ans*(n-ans)-m<<endl;
}
