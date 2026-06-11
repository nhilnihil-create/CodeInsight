#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

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

int main() {
    int n,m;
    cin >> n >> m;
    vector<ll>ans;
    vector<int>a(m),b(m);
    rep(i,m) {
      cin >> a[i] >> b[i];
      a[i]--;b[i]--;
    }
    reverse(a.rbegin(),a.rend());
    reverse(b.rbegin(),b.rend());
    ll tmp = (ll)n*(ll)(n-1)/2;
    ans.push_back(tmp);
    UnionFind uf(n);
    rep(i,m) {
      if(!uf.same(a[i],b[i])) {
          int sa = uf.size(a[i]);
          int sb = uf.size(b[i]);
          tmp -= (ll)sa*(ll)sb;
          ans.push_back(tmp);
          uf.unite(a[i],b[i]);
      } else {
          ans.push_back(tmp);
      }
    }
    reverse(ans.begin(),ans.end());
    for(int i = 1;i<=m;i++) {
        cout << ans[i] << endl;
    }
}