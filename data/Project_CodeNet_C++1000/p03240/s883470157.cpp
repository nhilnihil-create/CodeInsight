#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll x[N],y[N];
  ll h[N];
  int t;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] != 0) {
      t = i;
    }
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      ll tmp = abs(i - x[t]) + abs(j - y[t]) + h[t];
      bool can = true;
      for (int k = 0; k < N; k++) {
        if (h[k] == 0) {
          if (abs(i - x[k]) + abs(j - y[k]) < tmp) {
            can = false;
          }
        } else {
          if (abs(i - x[k]) + abs(j - y[k]) + h[k] != tmp) {
            can = false;
          }
        }
      }
      if (can) {
        cout << i << " " <<  j << " " << tmp << endl;
        return 0;
      }
    }
  }
  return 0;
}