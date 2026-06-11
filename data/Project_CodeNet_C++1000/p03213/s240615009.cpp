
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
// #define MOD1 998244353 
#define MEM_SIZE 100010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
 



map< int, int > prime_factor(int n) {
  map< int, int > ret;
  for(int i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}



void solve(void)
{
  int N;cin>>N;
  map<int,int> pf;
  for (int i = 1; i <= N; i++)
  {
    auto x = prime_factor(i);
    for (auto &&z : x)
    {
      pf[z.first] += z.second;
    }
    
  }
  vector<int> cnt(MEM_SIZE,0);
  for (auto &&x : pf)
  {
    cnt[x.second+1]++;
  }
  for (int i = MEM_SIZE-1; i >= 0; i--) 
  {
    cnt[i] += cnt[i+1];
  }
  // DEBUG(cnt);
  cout<<cnt[75] + cnt[25]*(cnt[3]-1)+(cnt[5]*(cnt[5]-1)/2*(cnt[3]-2)+cnt[15]*(cnt[5]-1));
  
  




  
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
