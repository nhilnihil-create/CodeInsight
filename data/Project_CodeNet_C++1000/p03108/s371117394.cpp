#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};


int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  UnionFind uf(n);
  rep(i, m){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  vector<ll> ans(m);
  ans[m-1]=(ll)n*(n-1)/2;
  for(int i=m-2; i>=0; i--){
    ll tmp=uf.size(a[i+1])*uf.size(b[i+1]);
    if(uf.same(a[i+1], b[i+1]))tmp=0;
    ans[i]=ans[i+1]-tmp;
    uf.unite(a[i+1], b[i+1]);
  }
  rep(i, m){
    cout << ans[i] << endl;
  }
  return 0;
}
