#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll Q;
  cin >> Q;
  vector<ll> A(Q), B(Q);
  REP(i, 0, Q) cin >> A[i] >> B[i];

  REP(i, 0, Q) {
    ll a = A[i], b = B[i];

    if(a > b) swap(a, b);

    if(a == b || a + 1 == b) {
      cout << a * 2 - 2 << endl;
    } else {
      ll c = sqrt(a * b);
      if(c * c == a * b) c--;
      if(c * (c + 1) >= a * b) {
        cout << c * 2 - 2 << endl;
      } else {
        cout << c * 2 - 1 << endl;
      }
    }
  }
}
