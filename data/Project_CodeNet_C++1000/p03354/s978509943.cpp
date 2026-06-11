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
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vl vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

//-------------------------------------------------------------------
#define MAX_N 1000000
int par[MAX_N];
int dep[MAX_N];

void init(int nu) {
  for(int iu=0;iu<nu;iu++){
    par[iu] = iu;
    dep[iu] = 0;
  }
}
int find(int xu){
  if(par[xu] == xu) return xu;
  return par[xu] = find(par[xu]);
}
void unite(int xu, int yu){
  xu=find(xu);
  yu=find(yu);
  if(xu == yu) return;
  if(dep[xu] < dep[yu]){
    par[xu] = yu;
  }else{
    par[yu] = xu;
    if(dep[xu] == dep[yu]) dep[xu]++;
  }
}
bool same(int xu, int yu){
  return find(xu) == find(yu);
}
//-------------------------------------------------------------------
int main(int argc, char const *argv[]) {
  ll n, m, a, b;
  std::cin >> n >> m;
  init(n+2);
  std::vector<ll> v(n);
  for(int i=0;i<n;i++) std::cin >> v[i];
  for(int i=0;i<m;i++){
    std::cin >> a >> b;
    unite(a, b);
  }
  std::vector<set<ll>> st(n+1);
  for(int i=0;i<n;i++) st[find(i+1)].insert(v[i]);
  ll ans = 0;
  for(int i=0;i<n;i++) if(st[find(i+1)].size()!=0&&st[find(i+1)].find(i+1)!=st[find(i+1)].end()) ans++;
  std::cout << ans << '\n';
  return 0;
}
