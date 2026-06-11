#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,k; cin >> a >> b >> c >> k;

  	ll ans = a - b;
  	if(k % 2 == 1) {
      ans *= -1; 
    }
  	
  	if(abs(ans) > 1000000000000000000) {
      cout << "Unfair" << endl;
    }
    cout << ans << endl;

    return 0;
}