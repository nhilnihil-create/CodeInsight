#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
#include<cmath>
#include<stack>
#include<tuple>
#include<numeric>
#include<cassert>

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pb push_back
#define DEBUG false

using namespace std;

using ll = long long;
using P = pair<int,int>;

const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll LINF=1LL<<60;
const int MAX_N = 200005;
const ll lmod = 1e9+7;

int dp[1<<26];
int a[MAX_N]; //[0,i)のハッシュ値
int C = 26;
string S;

int main(){
  cin >> S ;
  int N = S.size();
  rep(i,N){
    int b = S[i] - 'a';
    a[i+1] = a[i] ^ (1<<b);
  }
  fill(dp,dp+(1<<26),INF);
  dp[0] = 0;
  REP(i,1,N+1){
    rep(j,C){
      int bit = 1<<j;
      dp[a[i]] = min(dp[a[i]],dp[a[i]^bit]+1);
    }
  }
  cout << max(1,dp[a[N]]) << endl;
  return 0;
}
