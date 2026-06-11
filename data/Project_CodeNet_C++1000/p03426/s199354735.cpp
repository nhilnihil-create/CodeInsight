#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <sstream>   
#include<limits.h>
#include<float.h>
#include<list>
#include <array>
#include <complex>
using namespace std;
#define i64  long long
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000

// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){std::cout << e << std::endl;}
template<class T> void DEBUG(string str, T e){std::cout <<str << ">>" << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ DEBUG(v); } }
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T> void SORT_(std::vector<T>& v,bool GREATER = 0){if(GREATER == 0)sort(v.begin(),v.end());else{sort(v.begin(),v.end(),std::greater<T>());}}

void DFS(int V,vector<vector<int> >&GRAPH,vector<int>&dist,int depth)
{
  dist[V] = depth;
  for (int i = 0; i < GRAPH[V].size(); i++)
  {
    if(dist[GRAPH[V][i]] == -1)
    {
      DFS(GRAPH[V][i],GRAPH,dist,depth+1);
    }
  }
  return;
}
void solve(void)
{
  int H,W,D;
  cin>>H>>W>>D;
  map<int,pair<int,int> > mp;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int A;
      cin>>A;
      A--;
      mp[A] = pair<int,int>(i,j);
    }
  }
  vector<vector<pair<int,int> > > DATA(D);
  for (int i = 0; i < mp.size(); i++)
  {
    static auto itr = mp.begin();
    int A = itr->first;
    DATA[A%D].push_back(itr->second);
    itr++;
  }

  vector<vector<int> > dist(D);
  for (int i = 0; i < DATA.size(); i++)
  {
    dist[i].push_back(0);
    for (int j = 0; j < DATA[i].size()-1; j++)
    {
      pair<int,int> pos =DATA[i][j];
      pair<int,int> pos_n = DATA[i][j+1];
      dist[i].push_back(dist[i][j] + abs(pos.first - pos_n.first) + abs(pos.second - pos_n.second));
      
    }
    
  }
  // DEBUG(dist);
  int Q;
  cin>>Q;
  for (int i = 0; i < Q; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    int X = A/D;
    int Y = A%D;
    int D_1 = (B-A)/D;
    cout<<dist[Y][X+D_1] - dist[Y][X]<<endl;
  }
  
  
  


  
  
  
  return;
}


int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(9);
  solve();

 
  return 0;
}