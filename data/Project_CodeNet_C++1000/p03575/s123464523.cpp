#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

struct UnionFind{
    vector<int> d;
    UnionFind(int n=0):d(n,-1){}
    int root(int x){
        if(d[x]<0)return x;
        return d[x]=root(d[x]);
    }
    bool unite(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return false;
        if(d[x]>d[y])swap(x,y);
        d[x]+=d[y];
        d[y]=x;
        return true;
    }
    bool same(int x,int y){return root(x)==root(y);}
    int usize(int x){return -d[root(x)];}
};

int main(){
    int n,m;cin>>n>>m;
    V a(m);
    V b(m);
    for (int i = 0; i < m; ++i) {
        cin >>a[i]>>b[i];
        a[i]--;
        b[i]--;
    }
    ll ans=0;
    for (int i = 0; i < m; ++i) {
        UnionFind uni(n);
        for (int j = 0; j < m; ++j) {
            if(i==j)continue;
            uni.unite(a[j], b[j]);
        }
        if(uni.usize(0)!=n)ans++;
    }
    cout <<ans <<endl;
}

