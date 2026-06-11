#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  
  sort(a,a+3);
  
  ll ans = 0;
  if(a[0] % 2 == a[1] % 2 && a[0] % 2== a[2] % 2)
  {
    ans = (a[2] - a[0]) / 2 + (a[2] - a[1]) / 2;
  }else if(a[0] % 2 == a[1] % 2 && a[0] % 2 != a[2] % 2)
  {
    a[0]++; a[1]++;
    ans++;
    ans += (a[2] - a[0]) / 2 + (a[2] - a[1]) / 2;
  }else if(a[0] % 2 != a[1] % 2 && a[0] % 2 == a[2] % 2)
  {
    a[0]++; a[2]++;
    ans++;
    ans += (a[2] - a[0]) / 2 + (a[2] - a[1]) / 2;
  }else
  {
    a[1]++; a[2]++;
    ans++;
    ans += (a[2] - a[0]) / 2 + (a[2] - a[1]) / 2;
  }
  
  cout << ans << endl;
}