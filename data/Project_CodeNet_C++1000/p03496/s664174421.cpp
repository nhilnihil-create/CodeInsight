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
template<class T> void DEBUG(string str, T e){if(DEBUG_OUT == false)return;std::cout <<str << ">>" << e << std::endl;}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == 1)return;for(const auto& v : vv){ DEBUG(v); } }
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
template<typename T> void SORT_(std::vector<T>& v,bool GREATER = 0){if(GREATER == 0)sort(v.begin(),v.end());else{sort(v.begin(),v.end(),std::greater<T>());}}


//CODE
void solve(void)
{
  int N;
  cin>>N;
  vector<int> vec(N);
  int MAX = -1*INF;
  int MIN = INF;
  int MAX_index,MIN_index;
  for (int i = 0; i < N; i++)
  {
    cin>>vec[i];
    if(chmax(MAX,vec[i]))MAX_index = i;
    if(chmin(MIN,vec[i]))MIN_index = i;
  }

  vector<vector<int> > ANS;
  int MODE;
  if(abs(MAX) > abs(MIN)) MODE = 0;
  else MODE = 1;
  for (int i = 0; i < N; i++)
  {
    vector<int> tmp(2);
    if(MODE == 0)
    {
      if(vec[i] < 0)
      {
        vec[i] += MAX;
      tmp[0] = MAX_index;
      tmp[1] = i;
      ANS.push_back(tmp);
      }
    }
    else
    {
      if(vec[i] > 0)
      {
        vec[i] += MIN;
      tmp[0] = MIN_index;
      tmp[1] = i;
      ANS.push_back(tmp);
      }
    }
  }

  for (int i = 0; i < N-1; i++)
  {
    vector<int> tmp(2);
    if(MODE == 0)
    {
      tmp[0] = i;
      tmp[1] = i+1;
      ANS.push_back(tmp);
    }
    else
    {
      tmp[0] = N-1-i;
      tmp[1] = N-2-i;
      ANS.push_back(tmp);
    }
  }
  // DEBUG("MAX",MAX);
  // DEBUG("MIN",MIN);
  // DEBUG(vec);
  cout<<ANS.size()<<endl;
  for (int i = 0; i < ANS.size(); i++)
  {
    cout<<ANS[i][0]+1<<" "<<ANS[i][1]+1<<endl;
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