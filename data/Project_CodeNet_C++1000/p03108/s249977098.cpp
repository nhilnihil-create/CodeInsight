#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
#define vecmin(A) *min_element(A.begin(),A.end())
#define vecmax(A) *max_element(A.begin(),A.end())
typedef long long ll;

struct UnionFind{
  vector<ll> d;
  UnionFind(ll n=0): d(n,-1){}
  ll find(ll x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(ll x,ll y){
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(ll x, ll y) {
    return find(x) == find(y);
  }
  ll size(ll x) {
    return -d[find(x)];
  }
};

int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll> a(m);
  vector<ll> b(m);
  rep(i,m) cin >> a[i] >> b[i];
  a.push_back(0);
  b.push_back(0);
  reverse(a);
  reverse(b);
  vector<ll> ans(m+1,0);
  ans[0] = n*(n-1)/2;
  UnionFind tree(n+1);
  rep1(i,m){
    if(!tree.same(a[i],b[i])){
      ans[i] = ans[i-1] - tree.size(a[i])*tree.size(b[i]);
    }else ans[i] = ans[i-1];
    tree.unite(a[i],b[i]);
  }
  reverse(ans);
  rep1(i,m) cout << ans[i] << endl;
}
