#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
const int MOD = 1000000007;
using ll = long long;
using P = pair<int, int>;

struct UnionFind{
  vector<int> p;
  vector<ll> weight;
  UnionFind(int n){
    p.resize(n, -1);
    weight.resize(n, 0);
  }

  int find(int x){
    if(p[x] == -1)return x;
    else{
      int r = find(p[x]);
      weight[x] += weight[p[x]];
      return p[x] = r;
    }
  }

  ll get_weight(int x){
    find(x);
    return weight[x];
  }

  void unite(int x, int y, ll w){
    w += get_weight(x); 
    w -= get_weight(y); 

    x = find(x);
    y = find(y);
    if(x == y)return;
    p[y] = x;
    weight[y] = w;
  }

  ll diff(int x, int y){
    return get_weight(y) - get_weight(x);
  }
};

int main(){
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  for(int i = 0; i < m; ++i){
    int l, r;
    ll d;
    cin >> l >> r >> d;
    --l;
    --r;
    if(uf.find(l) == uf.find(r)){
      if(uf.diff(l, r) != d){
        cout << "No" << endl;
        return 0;
      }
    }
    else uf.unite(l, r, d);      
  }

  cout << "Yes" << endl;
  return 0;
}
