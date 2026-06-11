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

int fn(vector<int> &vec, int X,int MODE = 0)
{
  auto itr = lower_bound(ALL(vec),X);
  
  if(itr == vec.begin()&& MODE == 1) return -1*INF;
  else if(itr == vec.end()) return INF;
  else if(MODE == 1) return *itr;
  else return *(--itr);
}
void solve(void)
{
  int A,B,Q;
  cin>>A>>B>>Q;
  vector<int> vec1,vec2;
  for (int i = 0; i < A; i++)
  {
    int X;cin>>X;
    vec1.push_back(X);
  }
  for (int i = 0; i < B; i++)
  {
    int X; cin>>X;
    vec2.push_back(X);
  }
  vec1.push_back(INF);
  vec1.push_back(-1*INF);
  vec2.push_back(INF);
  vec2.push_back(-1*INF);
  sort(ALL(vec1));
  sort(ALL(vec2));
  for (int q = 0; q < Q; q++)
  {
    int X;cin>>X;
    int L1,L2,R1,R2;
    L1 = fn(vec1,X,0);
    L2 = fn(vec2,X,0);
    R1 = fn(vec1,X,1);
    R2 = fn(vec2,X,1);
    int D1 = abs(max(R1,R2) - X);
    int D2 = abs(min(L1,L2) - X);
    int D3 = min(abs(L1 - X)*2 + abs(R2 - X),abs(L1 - X) + abs(R2 - X)*2);
    int D4 = min(abs(L2 - X)*2 + abs(R1 - X),abs(L2 - X) + abs(R1 - X)*2);
    // DEBUG(L1,L2,R1,R2,X,"\n");
    cout<<min(min(D1,D2),min(D3,D4))<<endl;;
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
