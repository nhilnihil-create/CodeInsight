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

//CODE


void solve(void)
{
  int X,Y,Z,K;
  cin>>X>>Y>>Z>>K;
  vector<int>A(X),B(Y),C(Z);
  for (int i = 0; i < X; i++)
  {
    cin>>A[i];
  }
  sort(ALL(A),greater<int>());
  for (int i = 0; i < Y; i++)
  {
    cin>>B[i];
  }
  sort(ALL(B),greater<int>());
    for (int i = 0; i < Z; i++)
  {
    cin>>C[i];
  }
  sort(ALL(C),greater<int>());
  vector<int> vec;
  for (int i = 0; i < X; i++)
  {
    for (int j = 0; j < Y; j++)
    {
      for (int k = 0; k < Z; k++)
      {
        if((i+1)*(j+1)*(k+1) <= K) vec.push_back(A[i]+B[j]+C[k]);
        else break;
      }
      
    }
    
  }
  sort(ALL(vec),greater<int>());
  for (int i = 0; i < K; i++)
  {
    cout<<vec[i]<<endl;
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
