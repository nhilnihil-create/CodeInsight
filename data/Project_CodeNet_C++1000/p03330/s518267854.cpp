
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
// #define MOD1 998244353 
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

void solve(void)
{
  int N,C;
  cin>>N>>C;
  vector<vector<int> >  data (C,vector<int>(C,0));
  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < C; j++)
    {
       cin>>data[i][j];
    }
  }
  vector<vector<int> > vec (3);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int X;cin>>X;
      int M = (i+j)+2;
      vec[M%3].push_back(X);
    }
    
  }
  int res = INF;
  vector<vector<int> > cost (3,vector<int>(C,0));
  for (int i = 0; i < 3; i++)
  {
    for (int c = 0; c < C; c++)
    {
      int s = 0;
      for (auto &&x : vec[i])
      {
        s += data[x-1][c];
      }
      cost[i][c] = s;
    }
    
  }
  


  for (int c1 = 0; c1 < C; c1++)
  {
    for (int c2  = 0; c2  < C; c2 ++)
    {
      for (int c3 = 0; c3 < C; c3++)
      {
        if(c1 == c2 || c2 == c3 || c3 == c1)continue;
        int cost_s = 0;
        cost_s = cost[0][c1] + cost[1][c2] + cost[2][c3];
        chmin(res,cost_s);       

      }
      
    }
    
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
