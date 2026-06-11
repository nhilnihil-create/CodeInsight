#include <bits/stdc++.h> 
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
 
struct UnionFind
{
  vector<int> par;
  vector<int> sizes;
 
  UnionFind(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]); 
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
 
    if (x == y) return;

    if (sizes[x] < sizes[y]) swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  int size(int x) {
    return sizes[find(x)];
  }
};
 
int main(){
    ll n; cin>>n;
    ll m; cin>>m;
  	UnionFind uf(n);
    int a[m],b[m];
    rep(i,m){
         cin>>a[i]>>b[i];
         a[i]--;b[i]--;
    }
 
    ll rec=n*(n-1)/2;
    
    vector<ll> ans;
    ans.push_back(rec);
 
    
    for(int i=m-1;i>=0;i--){
            if(!uf.same(a[i],b[i])){
                ll t1=uf.size(a[i]);
                ll t2=uf.size(b[i]);
                rec -= t1*t2;
                uf.unite(a[i],b[i]);
                ans.push_back(rec);
            }
            else ans.push_back(rec);
    }
       
    for(int i=1;i<ans.size();i++){
        cout<<ans[ans.size()-1-i]<<endl;
    }
}