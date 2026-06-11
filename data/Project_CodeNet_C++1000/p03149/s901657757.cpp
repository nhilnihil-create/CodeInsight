#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> A(4); for (ll i = 0; i < 4; i++) cin >> A[i];
  sort(A.begin(), A.end());
  if (A[0] == 1 && A[1] == 4 && A[2] == 7 && A[3] && 9) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}