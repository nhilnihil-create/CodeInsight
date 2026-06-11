#include <bits/stdc++.h>
using namespace std;
int64_t zero = 0;

int gcd(int a, int b) {
  int x = max(a, b);
  int y = min(a, b);
  if(x % y == 0) {
    return y;
  }
  return gcd(y, x % y);
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  // 0からiの最大公約数
  vector<int> dp1(N, 1);
  //iからN - 1の最大公約数
  vector<int> dp2(N, 1);
  dp1.at(0) = A.at(0);
  for(int i = 1; i < N; i++) {
    dp1.at(i) = gcd(dp1.at(i - 1), A.at(i));
  }
  dp2.at(N - 1) = A.at(N - 1);
  for(int i = N - 2; i >= 0; i--) {
    dp2.at(i) = gcd(dp2.at(i + 1), A.at(i));
  }
  int ans = 1;
  for(int i = 0; i < N; i++) {
    if(i == 0) {
      ans = max(ans, dp2.at(1));
    }
    else if(i == N - 1) {
      ans = max(ans, dp1.at(N - 2));
    }
    else {
      ans = max(ans, gcd(dp1.at(i - 1), dp2.at(i + 1)));
    }
  }
  cout << ans << endl;
}