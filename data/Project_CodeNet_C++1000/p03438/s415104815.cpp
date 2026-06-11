#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  long long sma = 0;
  long long smb = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sma += a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    smb += b[i];
  }
  if (sma > smb) {
    cout << "No" << '\n';
    return 0;
  }
  long long diff = smb - sma;
  long long mv = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      mv += (b[i] - a[i] + 1) / 2;
    }
  }
  cout << (mv <= diff ? "Yes" : "No") << '\n';
  return 0;
}
