#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPS(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;
  ll h[10000000];
  ll dp[10000000];
  ll x = 1000000000000;
  
  REP(i,n){
    cin >> h[i];
  }
  REP(i,k+1){
    dp[i] = abs(h[0] - h[i]);
  }
  for (int i = k; i < (n); i++){
    
    REPS((j),1,k+1){
            if(x>abs(h[i]-h[i-j])+dp[i-j])
            {
                x=abs(h[i]-h[i-j])+dp[i-j];
            }        
    }
    dp[i] = x;
    x = 1000000000000;
  }
  
  cout << dp[n-1] << endl;
}
