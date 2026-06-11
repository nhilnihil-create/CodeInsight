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

// int DP[MEM_SIZE][MEM_SIZE] = {0};
// int GMEM[MEM_SIZE][MEM_SIZE] = {0};
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return;std::cout << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T> void DEBUG(string str, T e){if(DEBUG_OUT == false)return;std::cout <<str<<" ";DEBUG(e);};
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T> void SORT_(vector<int>& v,bool GREATER = 0){if(GREATER == 0)sort(v.begin(),v.end());else{sort(v.begin(),v.end(),std::greater<T>());}}

//CODE
int ASUM (int A)
{
  int res =0;
  for (int i = 1; i <= A; i++)
  {
    res += i;
  }
  return res;
}

void solve(void)
{
  int N;
  cin>>N;
  vector<int> data(N);
  for (int i = 0; i < N; i++)
  {
    cin>>data[i];
  }
  int prev = 0;
  int SUM = 0;
  int R = 0;
  int ANS = 0;
  int COUNT = 0;

  for (int L = 0; L < N; L++)
  {
    while((SUM + data[R]) == (prev^data[R])&&(R<N))
    {

      SUM += data[R];
      prev ^= data[R];
      R++;
    }
    
    if(L == R)
    {

      ANS++;
      SUM += data[R];
      prev ^= data[R];
      R++;
    }
    else
    {
      ANS += R - L;

      SUM -=data[L];
      prev ^=data[L];
    }
    // DEBUG("L R ANS SUM");
    // vector<int> temp = {L,R,ANS,SUM};
    // DEBUG(temp);
  }
  
  cout<<ANS<<endl;
  
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