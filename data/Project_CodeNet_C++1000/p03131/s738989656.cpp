#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll a,b,k;
  cin >> k >> a >> b;
  if(a+2 >= b) cout << k+1 << endl;
  else{
    if(a+1 > k){
      cout << k+1 << endl;
      return 0;
    }
    ll ans = b;
    k -= a+1;
    ans += (k/2)*(b-a);
    k %= 2;
    ans += k;
    cout << ans << endl;
  }
}