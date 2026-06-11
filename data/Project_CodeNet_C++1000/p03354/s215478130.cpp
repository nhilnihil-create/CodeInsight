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
 
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
struct UnionFind{
  vi par;
  UnionFind(int N) : par(N){
    rep(i, N) par[i] = i;
  }
  int root(int x){
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
  }
  bool same(int x, int y){
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  vi p(n);
  rep(i, n){
    int a;
    cin >> a;
    a--;
    p[i] = a;
  }
  UnionFind tree(n);
  rep(i, m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    tree.unite(x, y);
  }
  int ans = 0;
  rep(i, n){
    if(i == p[i]){
      ans++;
      continue;
    }
    if(tree.same(i, p[i])){
      ans++;
    }
  }
  cout << ans << endl;
}