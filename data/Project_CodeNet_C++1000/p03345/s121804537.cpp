#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  ll ans = 0;
  if (K % 2 == 0) {
    ans = A - B;
  }
  else {
    ans = B - A;
  }
  if (abs(ans) > 1000000000000000000) {
    cout << "Unfair" << endl;
  }
  else {
    cout << ans << endl;
  }
}
