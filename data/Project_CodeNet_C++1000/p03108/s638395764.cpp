#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

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
    ll n,m;cin >>n>>m;
    vector<ll>a(m);
    vector<ll>b(m);
    for (int i = 0; i < m; ++i) {
        cin >>a[i]>>b[i];
        a[i]--;b[i]--;
    }
    reverse(all(a));
    reverse(all(b));
    UnionFind uni(n);
    vector<ll>ans;
    ll U=n*(n-1)/2;
    for (int i = 0; i < m; ++i) {
        ans.push_back(U);
        if(!uni.same(a[i],b[i])) {
            U -= uni.usize(a[i]) * uni.usize(b[i]);
            uni.unite(a[i], b[i]);
        }
    }
    reverse(all(ans));
    for (int i = 0; i < m; ++i) {
        cout <<ans[i]<<endl;
    }
    return 0;
}
