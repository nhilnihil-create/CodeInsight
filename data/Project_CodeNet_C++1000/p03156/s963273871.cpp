#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
constexpr ll mod = ll(1e9 + 7);
 
int main () {
  ios::sync_with_stdio(0); cin.tie(0);
 
  int TT = 1;
  // cin >> TT;
  while (TT--) {
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> A(n);
    for (auto& aa : A) cin >> aa;
    ll na = 0, nb = 0, nm = 0;
    for (ll x : A) {
      if (x <= a) {
        ++na;
      } else if (x <= b) {
        ++nm;
      } else {
        ++nb;
      }
    }
    cout << min({na,nm,nb}) << endl;

    
  }
}
