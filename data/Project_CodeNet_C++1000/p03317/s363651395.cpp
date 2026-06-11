#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int n,k;
  cin >> n >> k;
  
  int a[n];
  rep(i,n) cin >> a[i];
  
  ll ans = 0;
  rep(i,n)
  {
    ans++;
    if(i+k > n-1)
      break;
    i += k-2;
  }
    
  cout << ans << endl;
}
