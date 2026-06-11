#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  ll n, x; cin >> n >> x;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  
  sort(a.begin(),a.end());
  int ans = 0;
  ll nokori = x;
  rep(i,n-1){
    ll want = a[i];
    if(nokori >= want){
        ans++;
        nokori -= want;
    }
  }

  if(a[n-1] == nokori) ans++;

  cout << ans << endl;

	return 0;
}

