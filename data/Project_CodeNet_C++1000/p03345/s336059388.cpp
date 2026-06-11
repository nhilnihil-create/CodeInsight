#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  
  ll ans;
  if (K % 2 == 0) {
    ans = A - B;
  }
  else {
    ans = B - A;
  }
  if (ans > 1000000000000000000 || ans < -1000000000000000000) {
    cout << "Unfair" << endl;
    return 0;
  }
  cout << ans << endl;
}