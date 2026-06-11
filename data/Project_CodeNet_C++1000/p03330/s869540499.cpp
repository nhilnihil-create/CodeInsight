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

using namespace std;
#define int  long long
 
#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(),(x).end()
// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class X> void DEBUG(X d, T e){if(DEBUG_OUT == false)return;std::cout <<d<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template< typename T > using matrix = vector< vector< T > >;

//FUNCTION  
void solve(void)
{
  int N,C;
  cin>>N>>C;
  vector<vector<int> > D(C,vector<int>(C));
  vector<map<int,int> > mp(3);
  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < C; j++)
    {
      cin>>D[i][j];
    }
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int A;
      cin>>A;
      A--;
      mp[(i+j+2)%3][A]++;
    }
  }
  
  vector<vector<int> > COST(3,vector<int>(C,0));
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < C; j++)
    {
      for (auto itr = mp[i].begin(); itr != mp[i].end(); itr++)
      {
        // if(i==2)DEBUG(itr->second);
        COST[i][j] += D[itr->first][j]*itr->second;
      } 
    }
  }
  // DEBUG(COST);
  int ANS = INF;
  for (int i = 0; i < C; i++)
  {
    for (int j = 0; j < C; j++)
    {
      for (int k = 0; k < C; k++)
      {
        if(i != j && j != k && k != i)
        {
          chmin(ANS,COST[0][i] + COST[1][j]+COST[2][k]);
        }
      }
    }
  }
  cout<<ANS<<endl;
  
  
  
  
  

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
