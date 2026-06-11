#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int A, B, T;
  cin >> A >> B >> T;
  int ans = 0;
  ans = T/A * B;
  cout << ans << endl;
}