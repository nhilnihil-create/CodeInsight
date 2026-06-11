
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
// #include<assert.h>
#include<random>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 10000
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }



void solve(void)
{ 
  int N,K;cin>>N>>K;
  string str;cin>>str;
  vector<pair<int,int> > vp;
  vp.emplace_back(-1,0);
  for (int i = 0; i < str.size(); i++)
  {
    int X = str[i] -'0';
    if(i == 0)
    {
      vp.emplace_back(X,1);
      continue;
    }
    if(vp.back().first == X)
    {
      vp.back().second++;
    }
    else
    {
      vp.emplace_back(X,1);
    }
  }
  for (int i = 0; i < vp.size()-1; i++)
  {
    vp[i+1].second += vp[i].second;
  }
  int res = 0;
  for (int i = 1; i <= vp.size()-1; i++)
  {
    int P = -1;
    if(vp[i].first == 0)
    {
      P = i + 2*K-1;
    }
    else
    {
      P = i + 2*K ;
    }
    if(P >= vp.size()) P = (int)vp.size()-1;
    chmax(res,vp[P].second - vp[i-1].second);
  }
  // for (auto &&i : vp)
  // {
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  
  cout<<res<<endl;
  
  
  
  
  return;
}
int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
