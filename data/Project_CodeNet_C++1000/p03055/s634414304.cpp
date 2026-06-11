#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
 
using ll = long long;
using P = std::pair<ll, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << #i <<" "<<i<<std::endl;
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<std::vector<ll>> graph(n);

  rep(i,0,n-1){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<ll> d(n,MOD);

  std::queue<ll> que;

  d[0]=0;
  que.push(0);

  while(!que.empty()){
    ll now=que.front();que.pop();

    for(ll next:graph[now]){
      if(chmin(d[next],d[now]+1)){
        que.push(next);
      }
    }
  }

  ll max=-1,itr=-1;

  rep(i,0,n){
    if(chmax(max,d[i]))itr=i;
  }

  rep(i,0,n)d[i]=MOD;

  d[itr]=0;
  que.push(itr);

  while(!que.empty()){
    ll now=que.front();que.pop();

    for(ll next:graph[now]){
      if(chmin(d[next],d[now]+1)){
        que.push(next);
      }
    }
  }

  max=-1;

  rep(i,0,n)chmax(max,d[i]);

  if(max%3==1)std::cout<<"Second";
  else std::cout<<"First";


  return 0;
}



