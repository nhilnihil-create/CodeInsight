#include <iostream>

using namespace std;

typedef long long ll;

ll a[100005];
ll b[100005];

int main() {
  int n;
  ll k;
  cin >> n >> k;

  for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

  ll ans = 0;

  for(int i = 0; i < n; i++) {
    if((k | a[i]) == k) ans += b[i];
  }
 
  for(int  i = 1; i < 30; i++) {
    ll s = (1ll << i);
    ll K = k;
    ll tmp = 0;
    if(k & s) {
      K >>= i;
      K <<= i;
      K--;
      for(int j = 0; j < n; j++) {
	if((K | a[j]) == K) tmp += b[j];
      }
      ans = max(ans,tmp);
    }
  }
  cout << ans << endl;
}
      
