#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int pref[100010]; 
int main() {
  int n;
  cin >> n;
  int a, b;
  ll ans = 0;
  rep(i,n) {
    cin >> a >> b;
    pref[i] = a+b;
    ans -= b;
  }
  sort(pref,pref+n,greater<int>());
  for (int i = 0; i < n; i += 2)
  {
    ans += pref[i];
  }
  cout << ans << endl;
  return 0;
}