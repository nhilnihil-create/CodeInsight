#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  cout << 0 << endl;
  string zero; cin >> zero;
  if (zero == "Vacant") return 0;
  string s;
  int left = 0, right = N;
  for (int i = 0; i < 19; i++) {
    int mid = (left + right) / 2;
    cout << mid << endl;
    cin >> s;
    if (s == "Vacant") return 0;
    if (mid % 2 == 0) {
      if (s == zero) left = mid;
      else right = mid;
    }
    else {
      if (s == zero) right = mid;
      else left = mid;
    }
  }
  return 0;
}