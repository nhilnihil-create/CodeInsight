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
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
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
//SOLVE

void solve(void)
{
  int H,W,N;cin>>H>>W>>N;
  int ix,iy;cin>>ix>>iy;
  ix--;iy--;
  string S,T;cin>>S>>T;
  int L = 0;int R = W;
  bool check = true;
  if(S[N-1] =='L')++L;
  if(S[N-1] =='R')--R;
  for (int i = N-2; i >= 0; i--) 
  {
    if(T[i] == 'L') R = min(R+1,W);
    else if(T[i] =='R') L = max(0LL,L-1);
    if(S[i] == 'L') L = L = L+1;
    else if(S[i] =='R') R = R - 1;;
    if(L >= R)check = false;
  }
  if(iy < L || iy >= R)check = false;
  L = 0,R = H;
  if(S[N-1] =='U')++L;
  if(S[N-1] =='D')--R;
  for (int i = N-2; i >= 0; i--) 
  {
    if(T[i] == 'U') R = min(R+1,H);
    else if(T[i] =='D') L = max(0LL,L-1);
    if(S[i] == 'U') L = L = L+1;
    else if(S[i] =='D') R = R - 1;;
    if(L >= R)check = false;
  }
  if(ix < L || ix >= R)check = false;

  if(check)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
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
