#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<ll>s(n);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    ans -= b;
    s[i] = b+a;
  }
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  for(int i = 0;i < n;i += 2) ans += s[i];
  cout << ans << endl;
}
