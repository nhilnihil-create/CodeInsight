#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,k;
  cin >> n >> k;
  
  ll h[n];
  rep(i,n) cin >> h[i];
  
  sort(h,h+n);
  
  ll ans = 1e9+1;
  for(int i = 0; i <= n-k; i++)
  {
    if(h[i+k-1] - h[i] < ans)
    {
      ans = h[i+k-1] - h[i];
    }
  }
  
  cout << ans << endl;
}