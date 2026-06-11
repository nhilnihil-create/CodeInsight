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



void solve(void)
{
  int N,K;
  cin>>N>>K;
  vector<vector<int> > MAT(N);
  for (int i = 0; i < N; i++)
  {
    int T,D;
    cin>>T>>D;
    MAT[T-1].push_back(D);
  }
  vector<int> A{0},B{0};
  for (auto &e : MAT)
  {
    if(e.empty())continue;
    sort(ALL(e));
    A.push_back(e.back());
    for (auto it = begin(e); it != end(e)-1; it++)
    {
      B.push_back(*it);
    }
    
  }
  sort(rbegin(A),rend(A)-1);
  sort(rbegin(B),rend(B)-1);


  for (int i = 0; i < A.size()-1; i++)
  {
    A[i+1] += A[i];
  }

  
  for (int i = 0; i < B.size()-1; i++)
  {
    B[i+1] += B[i];
  }
  int ANS = 0;
  //   DEBUG(A);
  // DEBUG(B);
  for (int x = max(1LL,K - ((int)B.size()-1)); x <= min(K,(int)A.size()-1) ;x++)
  {
    /* code */
    ANS = max(ANS,A[x] + B[K-x] + x*x);
    // DEBUG(x);
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
