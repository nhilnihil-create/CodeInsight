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

int n;
vvl a;
vl dp;
vb seen;

long dfs(long v){
  if(seen[v]) return dp[v];
  seen[v] = true;
  int m = __builtin_popcount(v);
  if(m <= 1) return dp[v] = 0;
  long ret = 0;
  rep(i,n){
    REP(j,i+1,n){
      if(((1<<i) & v) && ((1<<j) & v)) ret += a[i][j];
    }
  }
  for(long t = ((v-1)&v) ; t>0; t=(t-1)&v){
    ret = max(ret, dfs(t) + dfs(t^v));
  }
  return dp[v] = ret;
}

int main(){
  cin >> n;
  a = vvl(n,vl(n));
  rep(i,n) rep(j,n) cin >> a[i][j];
  dp = vl(1<<n,0);
  seen = vb(1<<n,false);
  cout << dfs((1<<n)-1) << endl;
}