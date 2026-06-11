#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
long long dp[200010];
  
int main()
{
  int N;
  cin >> N;
  vector<int> vecsix;
  vector<int> vecnine;
  int x = 6;
  while(x<=N){
    vecsix.push_back(x);
    x*=6;
  }
  int y = 9;
  while(y<=N){
    vecnine.push_back(y);
    y*=9;
  }

  REP(i,100010){
    dp[i]=INF;
  }
  dp[0]=0;
  dp[1]=1;
  REP(i,N){
    for(auto p:vecsix){
      chmin(dp[i+p],dp[i]+1);
    }
    for(auto p:vecnine){
      chmin(dp[i+p],dp[i]+1);
    }
    chmin(dp[i+1],dp[i]+1);
  }

  cout << dp[N] << endl;
}