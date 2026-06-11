#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, ans;
  cin >> N >> K;
  ans = 1;
  for (int i = 0; i < N; i++) {
     int mul, add;
     mul = ans * 2;
     add = ans + K;
     if (mul >= add) {
       ans = add;
     }
     else {
       ans = mul;
     }
  }
  cout << ans;
}
