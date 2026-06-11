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


//CODE
void solve(void)
{
  int N,M;
  cin>>N>>M;
  vector<vector<int> > data(N);

  for (int i = 0; i < N; i++)
  {
    int A,B,C;
    cin>>A>>B>>C;
    data[i].push_back(A);
    data[i].push_back(B);
    data[i].push_back(C);
  }

  int ANS = -1*I64_MAX;
  for (int i = 0; i < 8; i++)
  {

    vector<int> val(N,0);
    int X = 0,Y = 0,Z = 0;
    if(i&(1<<0))X=1;//1なら正 0なら負を加算
    if(i&(1<<1))Y=1;//1なら正 0なら負を加算
    if(i&(1<<2))Z=1;//1なら正 0なら負を加算


    // DEBUG("call");
    for (int j = 0; j < N; j++)
    {
    val[j] += (int)((X==1)?1:-1)*data[j][0];
    val[j] += (int)((Y==1)?1:-1)*data[j][1];
    val[j] += (int)((Z==1)?1:-1)*data[j][2];
    }
    

    sort(val.begin(),val.end(),greater<int>());
    int SUM = 0;
    for (int k = 0; k < M; k++)
    {
      SUM +=val[k];
      
    }
    // DEBUG(i);
    // DEBUG(SUM);
    chmax(ANS,SUM);
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
