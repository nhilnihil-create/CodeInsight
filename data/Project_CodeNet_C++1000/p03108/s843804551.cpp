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
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
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
  vector<pii> s(m);
  rep(i, m){
    int a,b; cin >> a >> b;
    s[i] = make_pair(a - 1, b - 1);
  }
  reverse(all(s));
  UnionFind tree(n);
  vector<ll> ans(m);
  ans[m - 1] = (ll)n * (n - 1) / 2;
  rep(i, m - 1){
    int x = s[i].first, y = s[i].second;
    if(tree.same(x, y)){
      ans[m - i - 2] = ans[m - i - 1];
    }else ans[m - i - 2] = ans[m - i - 1] - tree.size(x) * tree.size(y);
    tree.unite(x, y);
  }
  rep(i, m) cout << ans[i] << endl;
}