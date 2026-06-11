#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define ALL(a) (a).begin(), (a).end()
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d){
  depth[v] = d;
  //cout <<"v: " << v << endl;
  for (auto &e: tree[v]){
    //cout << "e.to: " << e.to << endl;
    if (e.to == p) continue;
    dfs(e.to, v, d+e.cost);
  }
}
*/

int main(void){
  int K;
  cin >> K;
  vector<bool> vis(K, false);
  deque<pair<int, int>> dq;
  dq.push_back(make_pair(1, 1));
  while(!dq.empty()){
    auto p = dq.front();
    dq.pop_front();
    int x = p.first;
    int d = p.second;
    //cout << "x: " << x << ", d: " << d << endl;
    if (vis[x]) continue;
    vis[x] = true;
    if (x == 0){
      cout << d << endl;
      return 0;
    }
    dq.push_back(make_pair((x+1)%K, d+1));
    dq.push_front(make_pair((10*x)%K, d));
  }
  return 0;
}
