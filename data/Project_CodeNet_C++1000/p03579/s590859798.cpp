#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

vvl G = vv(200000, 0, 0, ll);
vector<pair<bool, bool>> t(200000,  make_pair(false, false));

ll n, m;
void dfs(int now, int from, int mode){
  if(mode==1?t[now].second:t[now].first){
    std::cout << (n*(n-1))/2 - m << '\n';
    exit(0);
  }
  if(mode==1?t[now].first:t[now].second) return;
  (mode==1?t[now].first:t[now].second) = true;
  for(int i=0;i<G[now].size();i++){
    if(G[now][i]==from) continue;
    dfs(G[now][i], now, -1*mode);
  }
}
int main(int argc, char const *argv[]) {
  ll a, b;std::cin >> n >> m;
  re(i, m){
    std::cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, -1, 1);
  ll x = 0, y=0;
  for(int i=1;i<=n;i++){
    if(t[i].second) x++;
    if(t[i].first) y++;
  }
  std::cout << x*y - m << '\n';
  return 0;
}
