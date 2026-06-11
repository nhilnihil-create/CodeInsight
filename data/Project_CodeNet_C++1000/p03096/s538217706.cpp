//けんちょん見ました
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

vector<int> places[210000];
ll dp[210000];

int main(){
  ll n;
  cin >> n;
  vector<int>c(n);
  for(int i=0; i<n; i++) cin >> c[i];
  for(int i=0; i<n; i++) places[c[i]].push_back(i);
  
  dp[0]=1;
  for(int i=1; i<=n; i++){
    dp[i]=dp[i-1];
    
    ll color = c[i-1];
    ll it = lower_bound(places[color].begin(),places[color].end(),i-1)-places[color].begin();
    if(it>0){
      ll j = places[color][it-1];
      if((i-1)-j>1){
        dp[i]+=dp[j+1];
        dp[i]%=mod;
      }
    }
  }
  cout << dp[n] << endl;
}
  
  
  
