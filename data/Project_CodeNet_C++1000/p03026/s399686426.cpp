
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


//BELOW

void solve(void)
{ 
  int N;
  cin>>N;
  vector<vector<int> > GRAPH (N);
  for (int i = 0; i < N-1; i++)
  {
    int A,B;
    cin>>A>>B;
    A--;B--;
    GRAPH[A].push_back(B);
    GRAPH[B].push_back(A);
  }
  set<pair<int,int> > SET;
  vector<int> Vdata(N,0);
  for (int i = 0; i < N; i++)
  {
    SET.insert(make_pair(GRAPH[i].size(),i));
    Vdata[i] = GRAPH[i].size();
  }
  
  vector<int> vec (N,0);
  for (int i = 0; i < N; i++)
  {
     cin>>vec[i];
  }
  sort(ALL(vec));
  reverse(ALL(vec));
  int res = 0;
  vector<pair<int,int > > E;
  for (int i = 0; i < N; i++)
  {
    E.emplace_back(GRAPH[i].size(),i);
  }
  sort(ALL(E));
  reverse(ALL(E));
  vector<int> NUM(N,-1);
  for (int i = 1; i < N; i++)
  {
    res += vec[i];
  }
  int S = E[0].second;
  deque<int> q;
  q.push_back(S);
  int cnt = 0;
  NUM[S] = vec[cnt];
  cnt++;
  while(!q.empty())
  {
    int V = q.front();
    q.pop_front();
    for (auto &&nV : GRAPH[V])
    {
      if(NUM[nV] != -1)continue;
      NUM[nV] = vec[cnt];
      cnt++;
      q.push_back(nV);
    }
    
  }
  
  
  cout<<res<<endl;
  for (int i = 0; i < NUM.size(); i++)
  {
      if(i != 0)cout<<char(32);
      cout<<NUM[i];
  }
  cout<<endl;

  
  

  
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
