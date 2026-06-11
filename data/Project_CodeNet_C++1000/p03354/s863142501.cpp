#include <iostream> // cout, endl, cin
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
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<int> sizes; // size[i]:iの属する木の要素数

  UnionFind(int N) : par(N), sizes(N,1) { //最初は全てが根であるとして初期化
    for(int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x){
      return x;
    }
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) { // xとyの木を併合
    int rx = root(x); //xの根をrx
    int ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    if(sizes[rx]>sizes[ry]){ // 小さい方を大き方にくっつける
      par[ry]=rx;
      sizes[rx]+=sizes[ry];
    }
    else{
      par[rx]=ry;
      sizes[ry]+=sizes[rx];
    }
  }

  bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
    return root(x) == root(y);
  }

  int size(int x){
    return sizes[x]=sizes[root(x)];
  }
};

int main(){
  int N,M;
  cin >> N >> M;
  vector<int> P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
    P[i]--;
  }
  UnionFind uni(N);
  for(int i=0;i<M;i++){
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    uni.unite(x,y);
  }
  bool flag=true;
  while(flag){
    flag=false;
    for(int i=0;i<N;i++){
      if(i==P[i]){
        continue;
      }
      if(uni.same(i,P[i])){
        swap(P[i],P[P[i]]);
        flag=true;
      }
    }
  }
  int ans=0;
  for(int i=0;i<N;i++){
    if(i==P[i]){
      ans++;
    }
  }
  cout << ans << endl;
}