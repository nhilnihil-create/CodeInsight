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


template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }



void solve(void)
{
  int N,M; cin>>N; cin>>M;
  vector<vector<int> > vv (N,vector<int>(3,0));
  int ANS = -1*INF;
  for (int i = 0; i < N; i++)
  {
    cin>>vv[i][0]>>vv[i][1]>>vv[i][2];
  }
  for (int b = 0; b < 8; b++)
  {
    vector<int> data(N,0);
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if(((b>>j)&1))
        {
          data[i] += vv[i][j];
        }
        else
        {
          data[i] -= vv[i][j];
        }
        // if(b == 7)DEBUG(data[i]);
      //  data[i] = abs(data[i]); 
      }
    }
    sort(ALL(data),greater<int>());
    int SUM = 0;
    for (int k = 0; k < M; k++)
    {
      SUM += data[k];
    }
    // DEBUG(data);
    //     DEBUG(b,SUM,"\n");
    chmax(ANS,SUM);
    // if(ANS == 747)
    // {
    //   DEBUG(b,"\n");
    //   DEBUG(data);
    // }
    
    
    
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
