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
long long dp[10];
  
int main()
{
  int H,W;
  cin >> H >> W;
  vector<vector<int>> A(10,vector<int>(10));
  REP(i, 10){
    REP(j, 10){
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<int>> B(H,vector<int>(W));
  REP(i, H){
    REP(j, W){
      cin >> B.at(i).at(j);
    }
  }
  
  dp[1]=0;
  REP(i,10){
    dp[i]=A.at(i).at(1);
  }
  REP(k,100){
    REP(i,10){
      REP(j,10){
        chmin(dp[j],dp[i]+A.at(j).at(i));
      }
    }
  }
  ll ans=0;
  REP(i,H){
    REP(j,W){
      if(B.at(i).at(j)!=-1){
        ans+=dp[B.at(i).at(j)];
      }
    }
  }

  cout << ans << endl;
}