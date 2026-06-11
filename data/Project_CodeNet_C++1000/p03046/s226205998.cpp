#include <bits/stdc++.h>
using ll = long;
using namespace std;

int main(){
    ll m, k; cin >> m >> k;
    if (1ll<<m <= k) { cout << -1 << "\n"; return 0; }
    if (m == 1 && k == 1) { cout << -1 << "\n"; return 0; }
  if(m == 1 && k == 0) { cout << "0 0 1 1" << "\n"; return 0; }
    for (ll i = 0; i < (1ll<<m); i++) if (i != k) cout << i << " ";
    cout << k << " ";
    for (ll i = (1ll<<m) - 1; i >= 0; i--) if (i != k) cout << i << " ";
    cout << k <<  "\n";
    return  0;
}