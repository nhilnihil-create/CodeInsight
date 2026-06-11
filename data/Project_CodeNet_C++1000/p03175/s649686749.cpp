#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

struct Edge{
  int from;
  int to;
  long cost;
};

vvl dp(100010,vl(2,-1));

vector<vector<Edge>> Graph(100010);

long dfs(int v, int pv, int w){
  if(dp[v][w] != -1) return dp[v][w];
  long res = 1;
  for(Edge ed : Graph.at(v)){
    int nv = ed.to;
    if(pv == nv) continue;
    if(w) res = (res * (dfs(nv,v,1) + dfs(nv,v,0)) % MOD) % MOD;
    else res = (res * dfs(nv,v,1)) % MOD;
  }
  return dp[v][w] = res;
}

int main(){
  int n;
  cin >> n;
  rep(i,n-1){
    int x,y;
    cin >> x >> y;
    x--;y--;
    Graph.at(x).push_back({x,y,1});
    Graph.at(y).push_back({y,x,1});
  }
  cout << (dfs(0,-1,0) + dfs(0,-1,1)) % MOD << endl;
}
