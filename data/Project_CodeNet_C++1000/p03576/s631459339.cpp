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
  int N,K;
  cin>>N>>K;
  vector<pair<int,int> > DATA(N);
  for (int i = 0; i < N; i++)
  {
    cin>>DATA[i].first >> DATA[i].second;
  }
  sort(ALL(DATA));
  int ANS = I64_MAX;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int X1,X2,Y1,Y2;

      for (int k = 0; k < N; k++)
      {
        for(int m = 0; m < N; m ++)
        {
          X1 = min(min(DATA[i].first,DATA[j].first),min(DATA[k].first,DATA[m].first));
          Y1 = min(min(DATA[i].second,DATA[j].second),min(DATA[k].second,DATA[m].second));
          X2 = max(max(DATA[i].first,DATA[j].first),max(DATA[k].first,DATA[m].first));
          Y2 = max(max(DATA[i].second,DATA[j].second),max(DATA[k].second,DATA[m].second));
          int COUNT = 0;
          for (int l = 0; l < N; l++)
          {
            if(DATA[l].first >= X1 && DATA[l].first <= X2 && DATA[l].second >= Y1 && DATA[l].second <= Y2)
            {
              COUNT++;
            }
            
          }
          if(COUNT >= K)
          {
            chmin(ANS,(X2 - X1)*(Y2 - Y1));

          }
          
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
