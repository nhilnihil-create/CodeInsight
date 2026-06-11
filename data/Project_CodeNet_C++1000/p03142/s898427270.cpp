#include <assert.h>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cout << i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;

//非再帰トポロジカルソート 隣接リストを渡す 返り値のサイズがnじゃないならnot DAG
std::vector<ll> topo_sort(std::vector<std::vector<ll>>& graph){
  ll n=graph.size();
  std::vector<ll> ret,num(n,0);
  std::queue<ll> que;
  rep(i,0,n){
    for(ll j:graph[i])num[j]++;
  }
  rep(i,0,n){
    if(num[i]==0)que.push(i);
  }
  while(!que.empty()){
    ll u=que.front();que.pop();
    ret.push_back(u);
    for(ll i:graph[u]){
      num[i]--;
      if(num[i]==0)que.push(i);
    }
  }

  return ret;
}
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,m;
  std::cin>>n>>m;
  std::vector<std::vector<ll>> graph(n),graphinv(n);

  rep(i,1,n+m){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
    graphinv[b].push_back(a);
  }

  std::vector<ll> a=topo_sort(graph),ainv(n),ans(n);
  rep(i,0,n)ainv[a[i]]=i;
  ans[a[0]]=0;
  rep(i,1,n){
    ll now=a[i],max=-1;
    for(ll j:graphinv[now]){
      if(ainv[j]>max){
        ans[now]=j;
        max=ainv[j];
      }
    }
    ans[now]++;
  }

  rep(i,0,n)std::cout<<ans[i]<<"\n";
  return 0;
}