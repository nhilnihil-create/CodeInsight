#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() 
{
  ios::sync_with_stdio(0); 
  cin.tie(0); cout.tie(0);
  
  int n, k;
  cin >> n >> k;
  int x[n];
  for(int i = 0; i < n; i++)
     cin >> x[i];

  int ans = 1e18;

  for(int i = 0; i + k - 1 < n; i++){
      if(x[i] * x[i + k - 1] >= 0)
          ans = min(ans, max(abs(x[i]), abs(x[i + k - 1])));
      else
          ans = min(ans, abs(x[i]) + abs(x[i + k - 1]) + min(abs(x[i]), abs(x[i + k - 1])));
  }

  cout << ans;

  return 0;
}