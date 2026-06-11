# include <bits/stdc++.h>
using namespace std;

bool dp[2000005];
int main(){

  int n, a[2009], sum = 0;

  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i], sum += a[i];
  sort(a, a+n);
  dp[0] = true;

  for(int i=0; i<n; i++){
    for(int j=sum/2; j>=a[i]; j--){
      dp[j] |= dp[j-a[i]];
    }
  }

  for(int i=sum/2; i>=0; i--){
    if(dp[i]){
      cout << sum-i << endl;
      return 0;
    }
  }
  return 0;
}