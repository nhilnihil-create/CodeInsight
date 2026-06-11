#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
  
  ll n, sum=0;
  cin >> n;
  
  vector<ll> a(n);
  rep(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  ll mini = 1000000000;
  ll ans = 0;
  rep(i, 0, n) {
    if(abs(a[i]*n-sum) < mini) {
      mini = abs(a[i]*n-sum);
      ans = i;
    } 
  }
  cout << ans << "\n";
  
  //cout << (  ?"Yes" :"No") << "\n";

}