#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  for(int i=0;i<n;i++) cin >> c[i];
  c.erase(unique(c.begin(), c.end()), c.end());
  int C=*max_element(c.begin(),c.end());
  n=c.size();
  vector<ll> dp(n+1,0);
  dp[0]=1;
  vector<int> sm(C+1,0);
  for(int i=0;i<n;i++){
    dp[i+1]=(dp[i]+sm[c[i]])%MOD;
    sm[c[i]]+=dp[i];
    sm[c[i]]%=MOD;
  }
  cout << dp[n] << endl;
}