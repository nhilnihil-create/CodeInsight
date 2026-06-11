#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;
  ll mini = min(n, m);
  ll maxi = max(n, m);
  ll ans;
  
  if(mini==1) {
    if(maxi==1) ans = 1;
    else ans = maxi-2;
  }
  else ans = (mini-2)*(maxi-2);
    
  cout << ans << "\n";
}