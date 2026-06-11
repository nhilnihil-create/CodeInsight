#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0; i<n; i++) 
    cin >> a[i];
  // dp[i] : TRUE if first player wins with i stones left
  vector<bool> dp(k+1);
  for(int i=0; i<=k; i++) {
    for(int x : a) {
      if(i>=x && !dp[i-x])
        dp[i] = true;
    }
  }
  cout << (dp[k]? "First" : "Second") << '\n';

  return 0;
}