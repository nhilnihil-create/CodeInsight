#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e16
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
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
long long dp[150];

ll GetDigit(ll num){
    ll digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

int main()
{
  ll X;
  cin >> X;

  REP(i,150){
    dp[i] = INF;
  }

  REP(i,10){
    dp[i] = i;
  }

  FOR(i,1,150){
    FOR(j,1,10){
      ll a = 1;
      ll b = GetDigit(dp[i]);
      REP(k,b){
        a*=10;
      }
      chmin(dp[i+j],dp[i]*10+j);
      chmin(dp[i+j],dp[i]+(j*a));
    }
  }

  
  int MAX = 0;
  REP(i,150){
    if(dp[i]<=X){
      chmax(MAX,i);
    }
  }
 
  cout << MAX << endl;
}