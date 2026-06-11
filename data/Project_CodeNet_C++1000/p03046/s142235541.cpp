#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll M, K;
  cin >> M >> K;
  if (K == 0) {
    for (ll i = 0; i < (1 << M); i++) cout << i << " " << i << " ";
    cout << endl;
    return 0;
  } else if (M >= 2) {
    for (ll i = 0; i < (1 << M); i++) {
      if ((i ^ K) < (1 << M)) {
        ll left = i, right = i ^ K;
        cout << left << " ";
        for (ll j = 0; j < (1 << M); j++) {
          if (j == left || j == right) continue;
          cout << j << " ";
        }
        cout << left << " " << right << " ";
        for (ll j = (1 << M) - 1; j >= 0; j--) {
          if (j == left || j == right) continue;
          cout << j << " ";
        }
        cout << right;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}