#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  ll n; cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= n; i++){
    ll a = n / i, b = n % i;
    //cout << n / i << " " << n % i << endl;
    if(a > b) continue;
    i += b / a;
    if(b % a == 0) ans += i - 1;
  }
  cout << ans << endl;
  return 0;
}
