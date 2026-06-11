#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<ll>a(n);
  rep(i,0,n) cin >> a[i];
  if(a[0] != 0){cout << -1 << endl;return 0;}
  ll ans = 0;
  rep(i,1,n){
    if(a[i]-a[i-1] > 1){cout << -1 << endl;return 0;}
    else if(a[i]-a[i-1] == 1) ans++;
    else ans += a[i];
  }
  cout << ans << endl;
}