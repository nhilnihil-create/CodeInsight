#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
const double EPS = 1e-9;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define SZ(x) ((int)(x).size())
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


vector<ll> checked;
ll dfs(vector<vector<ll>> &G, ll v){
  ll ret = 0;
  for(ll v_next: G[v]){
    if(checked[v_next] >= 0){
      chmax(ret, checked[v_next]);
      continue;
    }
    chmax(ret, dfs(G, v_next));
  }
  checked[v] = ++ret;
  return ret;
}
int main(){
  ll n,m; cin>>n>>m;
  vector<vector<ll>> G(n);
  checked.assign(n,-1);
  rep(i,m){
    ll x,y; cin>>x>>y;
    x--,y--;
    G[x].push_back(y);
  }
  ll ans=0;
  rep(i,n){
    chmax(ans, dfs(G, i));
  }
  cout<<--ans<<endl;
}