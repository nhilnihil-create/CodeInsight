#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

void solve(){
  ll a, b, k;
  cin >> a >> b >> k;
  ll ans = min(a, b);
  for(ll i = min(a, b); i>=1; --i){
    if(a%i == 0 && b%i == 0){
      ans = i;
      --k;
    }
    if(!k)
      break;
  }
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
