#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ar array
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  int ans = 0;
  ans += a[2]-a[1];
  a[0] += ans;
  a[1] += ans;
  ans += ((a[2]-a[0])/2)+((a[2]-a[0])%2)+((a[2]-a[0])%2);
  cout << ans << '\n';
  return 0;
}
