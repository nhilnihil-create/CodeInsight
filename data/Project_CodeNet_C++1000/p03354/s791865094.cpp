#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1LL<<60;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------
// http://drken1215.hatenablog.com/entry/2019/05/28/124300
// けんちょんさんのUnion Find
struct UnionFind {
    vector<int> par, w;

    UnionFind(int n) : par(n, -1), w(n, 0) { }
    void init(int n) { par.assign(n, -1); w.assign(n, 0); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) {
            ++w[x];
            return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        ++w[x];
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }

    int wei(int x) {
        return w[root(x)];
    }
};

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> a(N);
  for(int i=0; i<N; i++){
    cin >> a[i];
    a[i]--;
  }
  UnionFind uf(N);
  for(int i=0; i<M; i++){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    uf.merge(a[x],a[y]);
  }
  int ans = 0;
  for(int i=0; i<N; i++){
    if(uf.issame(i,a[i])){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
