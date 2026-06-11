#include <bits/stdc++.h>

int main(){
  using namespace std;
  using ll = long long;
  ll q; cin >> q;
  while(q--) {
    ll a,b; cin >> a >> b;
    if(a>b) swap(a,b);
    if (a == b || a + 1 == b) {
      cout<< a * 2 - 2 << endl;
    } else {
      ll c = sqrt(a * b);
      if (c * c == a * b) c--;
      cout << c * 2 - (c * (c + 1) >= a * b ? 2 : 1) << endl;
    }
  }
}