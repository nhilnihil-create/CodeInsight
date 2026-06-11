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
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return;std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class X> void DEBUG(X d, T e){if(DEBUG_OUT == false)return;std::cout <<d<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

  // vector<vector<vector<int> > > DP =  vector<vector<vector<int> > >(100001,vector<vector<int> >(2,vector<int>(2,0)));
void solve(void)
{
  int N;
  cin>>N;
  string str;
  cin>>str;
  vector<int> W(N,0),B(N,0);
  int NW = 0;
  int NB = 0;
  for (int i = 0; i < N; i++)
  {
    if(str[i]=='#')
    {
      B[i]++;
      NB++;
    }
    else
    {
      W[i]++;
      NW++;
    }
    
  }
  for (int i = 0; i < N-1; i++)
  {
    W[i+1] += W[i];
  }
  for (int i = 0; i < N-1; i++)
  {
    B[N-2-i] += B[N-1-i];
  }
  //   for (int i = 0; i < N-1; i++)
  // {
  //   B[i+1] += B[i];
  // }
  // for (int i = 0; i < N-1; i++)
  // {
  //   W[N-2-i] += W[N-1-i];
  // }
  for (int i = 0; i < N; i++)
  {
    W[i] = NW - W[i];
    B[i] = NB - B[i];
  }
  
  // DEBUG(W);DEBUG(B);
  
  int ANS = INF;
  for (int i = 0; i < N; i++)
  {
    chmin(ANS,W[i]+B[i]);
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
