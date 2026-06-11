#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e10;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double



////////////////////////////////////////////////////////////////////
template<typename T>
struct edge {
  int to, from;T cost;
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
template<typename T>
using edges = vector<edge<T>>;
template<typename T>
using graph = vector<edges<T>>;
template<typename T>
using matrix = vector<vector<T>>;

template<typename T>
bool compByCost(const edge<T>& left, const edge<T>& right){
  return left.cost < right.cost; 
}

////////////////////////////////////////////////////////////////////i

int n,m;graph<int> g(110000);
int h[110000], ans[110000];
signed main(){
  cin>>n>>m;
  rep(i,n+m-1){
    int a, b;cin>>a>>b;a--;b--;
    g[a].push_back(edge<int>(b, -1));
    h[b]++;
  }
  int root;rep(i,n)if(h[i] == 0)root = i;
  queue<int> que;que.push(root);
  while(!que.empty()){
    int p = que.front();que.pop();
    rep(i,g[p].size()){
      int to = g[p][i].to;
      if(h[to] == 1){
        ans[to] = p+1;
        h[to] = 0;
        que.push(to);
      }else{
        h[to]--;
      }
    }
  }
  rep(i,n)cout << ans[i] << endl;
}
