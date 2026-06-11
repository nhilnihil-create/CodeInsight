#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  int cnt = 0;
  rep(i,n) {
    if(a[i]<0) {
      cnt++;
      a[i] *= -1;
    }
  }

  ll ans = 0;
  sort(a.begin(),a.end());
  rep(i,n) ans += a[i];

  if(cnt%2 == 1) ans -= 2*a[0];
  
  cout << ans << endl;
}

