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

const ll MOD=1000000007LL;

ll H,W;
vvll dp;
bool isout( ll y, ll x){
  return y<0 || y>=H || x<0 || x>=W;
}
ll dfs(vector<string> &field, ll y, ll x){
  if(dp[y][x] >= 0) return dp[y][x];
  if(y==H-1&&x==W-1) return 1LL;
  ll cnt=0;
  if(!isout(y+1,x) && field[y+1][x]=='.'){
    cnt+=dfs(field,y+1,x);
    cnt%=MOD;
  }
  if(!isout(y,x+1) && field[y][x+1]=='.'){
    cnt+=dfs(field,y,x+1);
    cnt%=MOD;
  }
  return dp[y][x] = cnt;
}
int main(){
  cin>>H>>W;
  dp.assign(H,vll(W,-1));
  vector<string> field(H);
  rep(i,H){
    string s; cin>>s;
    field[i]=s;
  }
  ll ans=dfs(field,0,0);
  cout<<ans<<endl;
}