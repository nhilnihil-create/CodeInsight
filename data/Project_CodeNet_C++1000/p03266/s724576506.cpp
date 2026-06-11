#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for(int a=1; a<=n; a++){
    ll arem = a % k;
    ll brem = k - arem;
    ll crem = brem;
    if((brem+crem)%k==0){
      ans += pow((n-brem)/k+1,2);
    }
    else continue;
    //cout << ans << endl;
  }
  cout << ans << endl;
}