#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  string S;
  ll kaisuu = 0;
  if(N == 0) { cout << 0; return 0; }
  while(N != 0) {
    int r;
    if(N % 2 < 0) r = (N % 2) + 2;
    else r = (N % 2);
    S += (char)('0' + r);
    N = (N - r) / (-2);
  }
  reverse(S.begin(), S.end());
  cout << S;
    return 0;
}
