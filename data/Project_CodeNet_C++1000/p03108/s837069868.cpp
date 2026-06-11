#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }

  UnionFind uf(n);
  vector<ll> ans(m);
  ans[m-1] = (ll)n * (n-1) / 2;
  for(int i=m-1; i>0; i--) {
    int x=a[i], y=b[i];
    if(uf.find(x,y)) {
      ans[i-1] = ans[i];
      continue;
    }
    ans[i-1] = ans[i] - ((ll)uf.size(x) * (ll)uf.size(y));
    uf.unite(x,y);
  }
  for(auto i : ans) cout << i << endl;
}
