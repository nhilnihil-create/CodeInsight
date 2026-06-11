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
    ll n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<ll>a(m),b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    vector<ll>ans(m);
    ans[m-1] = n*(n-1)/2;
    for(int i = m-1;i>0;i--) {
        if(uf.same(a[i],b[i])) {
            ans[i-1] = ans[i];
        } else {
            ll size_a = uf.size(a[i]);
            ll size_b = uf.size(b[i]);
            ans[i-1] = ans[i] - size_a*size_b;
        }
        uf.unite(a[i],b[i]);
    }
    
    rep(i,m) cout << ans[i] << endl;
}



