#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int n, d, x;
  cin >> n >> d >> x;
  int a[n];
  rep(i,n) cin >> a[i];
  int ans = x;
  rep(i,n){
    if(d % a[i]) ans++;
    ans += d /a[i];
  }
  cout << ans << endl;
  return 0;
}
