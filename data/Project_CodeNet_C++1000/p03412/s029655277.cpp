#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[32][200010];
ll b[32][200010];
ll c[32];
int n;
/*
int f(int k, ll upper, ll lower) {
  ll up = -1;
  for (ll i = 30; i >= 0; i--) {
    if (up + c[i] >= n) continue;
    if (b[k][up+c[i]] < upper) {
      up += c[i];
    }
  }
  ll low = -1;
  for (ll i = 30; i >= 0; i--) {
    if (low + c[i] >= n) continue;
    if (b[k][low+c[i]] < lower)
      low += c[i];
  }
  return up - low;
}
*/

int f(int k, ll upper, ll lower) {
  return upper_bound(b[k],b[k]+n,upper)-lower_bound(b[k],b[k]+n,lower);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <= 31; i++) {
    c[i] = (1LL << i);
  }
  for (int i = 0; i < n; i++) cin >> a[0][i];
  for (int i = 0; i < n; i++) cin >> b[0][i];
  for (int i = 1; i < 31; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = a[0][j] % c[i];
      b[i][j] = b[0][j] % c[i];
    }
    sort(b[i],b[i]+n);
  }

  ll ans = 0;
  for (ll i = 1; i < 31; i++) {
    ll cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += f(i, c[i]-a[i][j]-1, c[i-1]-a[i][j])
          + f(i, c[i+1]-a[i][j]-1, c[i-1]*3-a[i][j]);
    }
    if (cnt%2)
    ans |= c[i-1];
  }

  cout << ans << endl;
  return 0;
}
