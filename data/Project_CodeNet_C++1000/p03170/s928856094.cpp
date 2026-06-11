#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  vector<bool> dp(200005, false);
  for(int i=0; i<=k; ++i){
    if(!dp[i]){
      for(int j=0; j<n; ++j){
        dp[i+an[j]] = true;
      }
    }
  }
  if(dp[k]) cout << "First" << endl;
  else cout << "Second" << endl;
}