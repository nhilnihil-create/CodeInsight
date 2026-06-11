#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<int> p(n);
  rep(i, n){
    cin>>p[i];
    p[i]--;
  }

  vector<int> dp(n+1, 0);
  int max_c = 0;
  rep(i, n){
    int t=p[i];
    dp[t] = dp[t-1]+1;
    max_c = max(max_c, dp[t]);
  }

  cout<<n-max_c;

  return 0;
}