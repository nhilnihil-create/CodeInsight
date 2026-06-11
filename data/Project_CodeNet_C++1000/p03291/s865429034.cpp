#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;





int main(void) {
  string s;
  cin >> s;
  ll i, j;
  ll N=(ll)s.size();
  ll dp[MAX][5]={};
  
  dp[0][0]=1;
  for(i=0; i<N; i++) {
    for(j=0; j<4; j++) {
      if(s[i]=='?')
        dp[i+1][j]=dp[i][j]*3%MOD;
      else
        dp[i+1][j]=dp[i][j];
    }
    
    ll c=s[i];
    if(c=='A') {
      moC(dp[i+1][1], +, dp[i][0]);
    }else if(c=='B') {
      moC(dp[i+1][2], +, dp[i][1]);
    }else if(c=='C') {
      moC(dp[i+1][3], +, dp[i][2]);
    }else if(c=='?') {
      for(j=0; j<3; j++) {
        moC(dp[i+1][j+1], +, dp[i][j]);
      }
    }
    
  }
  
  pt(dp[N][3]);
  
}




