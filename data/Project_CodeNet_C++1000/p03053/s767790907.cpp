#include<bits/stdc++.h>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 100010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

 template< typename T >
struct edge {
  int src, to;
  T cost;
 
  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
 
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
 
  edge &operator=(const int &x) {
    to = x;
    return *this;
  }
 
  operator int() const { return to; }
};
 
template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
 

vector<int> dijkstra(WeightedGraph<int> &G,int s)
{ 
  
  vector<int> path(G.size(),I64_MAX);
  path[s] = 0;
  priority_queue <pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > que;
 
  que.emplace(path[s],s);
 
  while(!que.empty())
  {
    int cost;
    int idx;
    tie(cost,idx) = que.top();
    que.pop();
 
    if(path[idx] < cost) continue;
    for (auto &e: G[idx])
    {
      int next_cost = cost + e.cost;
      if(path[e.to] <= next_cost) continue;
      path[e.to] = next_cost;
      que.emplace(path[e.to],e.to);
    }
  }
 
  return path;
}
 
//SOLVE
void solve(void)
{
  int H,W;
  cin>>H>>W;
  vector<vector<char> > GRID(H,vector<char>(W));
  pair<int,int> START,GOAL;
  vector<pair<int,int> > BLACK;
  int ANS = 0;
  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      cin>>GRID[h][w];
      if(GRID[h][w] == '#')
      {
        BLACK.push_back(make_pair(h,w));
        START = make_pair(h,w);
      }
    }
  }
  // START.first = 0;START.second=0;
  // GOAL.first = H-1;GOAL.second=W-1;
  int N = H*W;
  // DEBUG(GRID);
  WeightedGraph<int> WG(N);
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      edge<int> e (-1,-1,-1);
      int V = i*W + j;
      int WEIGHT = 0;
      if(i != H-1)
      {
        int nV = V + W;
        WEIGHT = 1;
        e.src = V;
        e.to = nV;
        e.cost = WEIGHT;
        WG[V].push_back(e);
        e.to = V;
        e.src = nV;
        WG[nV].push_back(e); 
      }
      if(j != W-1)
      {
        int nV = V + 1;
        WEIGHT = 1;
        e.src = V;
        e.to = nV;
        e.cost = WEIGHT;
        // DEBUG(WEIGHT);
        WG[V].push_back(e);
        e.to = V;
        e.src = nV;
        WG[nV].push_back(e); 
      }
    }
  }
  int S = START.first*W + START.second;
  for (int i = 0; i < BLACK.size()-1; i++)
  {
    int V = BLACK[i].first*W + BLACK[i].second;
    int nV = BLACK[i+1].first*W + BLACK[i+1].second;
    WG[V].emplace_back(V,nV,0);
    WG[nV].emplace_back(nV,V,0);
    
  }
  
  vector<int> path = dijkstra(WG,S);
  // DEBUG(path);
  int res = 0;
  // DEBUG(path);
  for (int i = 0; i < H*W; i++)
  {
    chmax(res,path[i]);
  }
  cout<<res<<endl;
  
  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
