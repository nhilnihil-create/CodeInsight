#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll a, b; cin >> a >> b;
  char c[100][100];
  for (ll i = 0; i < 50; i++) {
    for (ll j = 0; j < 100; j++) {
      c[i][j] = '#';
      c[i+50][j] = '.';
    }
  }
  ll island = 1;
  for (ll i = 0; i < 50; i++) {
    for (ll j = 0; j < 100; j++) {
      if (island <= a-1 && i%2 == 0 && j%2 == 0) {
        c[i][j] = '.';
        island++;
      }
    }
  }
  island = 1;
  for (ll i = 99; i >= 50; i--) {
    for (ll j = 0; j < 100; j++) {
      if (island <= b-1 && i%2 == 1 && j%2 == 0) {
        c[i][j] = '#';
        island++;
      }
    }
  }
  cout << 100 << " " << 100 << endl;
  for (ll i = 0; i < 100; i++) {
    for (ll j = 0; j < 100; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }
}