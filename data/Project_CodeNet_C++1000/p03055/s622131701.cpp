
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
#include<stdio.h>
#include<string.h>
#include <bitset>
// #include<assert.h>
#include<random>
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

void dfs(int v,int p ,int d,vector<vector<int> > &GRAPH ,vector<int>& dist)
{
  dist[v] = d;
  for (auto &&i : GRAPH[v])
  {
    if(i == p)continue;
    dfs(i,v,d+1,GRAPH,dist);
  }
  
  return;
}

void solve(void)
{
  int n;
  cin>>n;
  vector<vector<int> > GRAPH (n);
  for (int i = 0; i < n-1; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    GRAPH[A].push_back(B);
    GRAPH[B].push_back(A);
  }
  vector<int> dist(n,0);
  int sv = -1;
  int m = -1;
  dfs(0,-1,0,GRAPH,dist);
  for (int i = 0; i < n; i++)
  {
    if(chmax(m,dist[i]))
    {
      sv = i;
    }
  }
  dfs(sv,-1,0,GRAPH,dist);
  m = -1;
  for (size_t i = 0; i < n; i++)
  {
    chmax(m,dist[i]);
  }
  // DEBUG(m);
  m--;
  if(m%3 != 0)
  {
    cout<<"First"<<endl;
  }
  else
  {
    cout<<"Second"<<endl;
  }
  
  
  
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
