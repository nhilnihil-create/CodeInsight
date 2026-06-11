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
template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }


void solve(void)
{
  int N;
  cin>>N;
  vector<vector<int> > vv (N,vector<int>(3,0));
  for (int i = 0; i < N; i++)
  {
    cin>>vv[i][0]>>vv[i][1]>>vv[i][2];
  }

  for (int x = 0; x < 101; x++)
  {
    for (int y = 0; y < 101; y++)
    {
      int check = 1;
      int H = 0;
      int valid = 0;
      for (int i = 0; i < N; i++)
      {
        int dx = vv[i][0];
        int dy = vv[i][1];
        int dh = vv[i][2];
     
        if(valid == 0)
        {
          if(dh != 0)
          {
          H = dh +abs(x -dx) + abs(y-dy);
          if(dh > 0 && H > 0)
          { valid = 1;
            i = -1;
          }
          }
        }
        else
        {
          if(dh != max(0LL,H - abs(x-dx) - abs(y -dy)))
          { check = 0;
          }
          else
          {
            // DEBUG(H,dx,dy,dh,x,y,"\n");
          }
        }   
      }
      if(check == 1)
      {
        cout<<x<<" "<<y<<" "<<H<<endl;
        return;
      }
      
    }
    
  }
  
  
  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(15);
  solve();

  return 0;
}
