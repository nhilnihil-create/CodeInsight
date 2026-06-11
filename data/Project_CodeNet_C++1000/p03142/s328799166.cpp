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
#define rep(a, b, c) for(ll c=a;c<b;c++)
#define re(b, c) for(ll c=0;c<b;c++)
typedef long long int ll;
typedef long double ld;
using namespace std;

vvl G = vv(100001, 0, 0, ll);
vector<set<ll>> T(100001);
vll per(100001, 0);
deque<vll> q;
void bfs(ll now, ll from){
  if(T[now].size()==1||from==0){
    per[now] = from;
    for(int i=0;i<G[now].size();i++){
      q.push_back(vll{G[now][i], now});
    }
  }else{
    T[now].erase(from);
  }
}
int main(int argc, char const *argv[]) {
  ll x, y, n, m;std::cin >> n >> m;
  for(int i=0;i<n-1+m;i++){
    std::cin >> x >> y;
    G[x].push_back(y);
    T[y].insert(x);
  }
  ll root=-1;
  for(int i=1;i<=n;i++) if(T[i].size()==0&&root==-1) root = i;

  q.push_back(vll{root, 0});
  while(!q.empty()){
    vll t = q.front();q.pop_front();
    bfs(t[0], t[1]);
  }
  for(int i=1;i<=n;i++) std::cout << per[i] << '\n';
  return 0;
}
