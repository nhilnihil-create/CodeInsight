#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
struct UnionFind {
  vi d;
  UnionFind(int n): d(n,-1) {}
  int root(int x) {
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -d[root(x)];
  }
};
int main(){
  int n,m;
  cin >> n >> m;
  vi a(m), b(m);
  rep(i, m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<ll> ans(m, 0);
  ans[m - 1] = (ll)n * (n - 1) / 2;
  UnionFind tree(n);
  for(int i = m - 1; i > 0; i--){
    if(!tree.same(a[i], b[i])){
      ans[i - 1] = ans[i] - tree.size(a[i]) * tree.size(b[i]);
    }else{
      ans[i - 1] = ans[i];
    }
    tree.unite(a[i], b[i]);
  }
  rep(i, m) cout << ans[i] << endl;
}