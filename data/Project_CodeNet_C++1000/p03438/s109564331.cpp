#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N), D(N);
  for (auto &e : A) cin >> e;
  for (auto &e : B) cin >> e;
  ll del = 0;
  bool b = true;
  for (ll i = 0; i < N; i++) {
    D[i] = B[i]-A[i];
     if (D[i] != 0) b = false;
    del += D[i];
  }
  if (b) cout << "Yes" << endl;
  else if (del < 0) cout << "No" << endl;
  else {
    sort(D.begin(),D.end(),greater<ll>());
    ll L = 0, R = N-1;
    while (L < R) {
      if (D[L] == 1) {
        del -= 1;
        D[L] = 0;
        L++;
      }
      else if ((D[L]+1)/2 > D[R]*(-1)) {
        del += D[R];
        D[L] += 2*D[R];
        D[R] = 0;
        R--;
      }
      else {
        del -= D[L]/2;
        D[R] += D[L]/2;
        D[L] = D[L]%2;
        if (D[R] == 0) R--;
        if (D[L] == 0) L++;
      }
      if (del < 0) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
}