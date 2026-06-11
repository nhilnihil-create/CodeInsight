#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N,T,A;
  cin >> N >> T >> A;
  int H[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  T *= 1000;
  A *= 1000;
  int ans = -1;
  ll min_diff = 99999999;
  for (int i = 0; i < N; i++) {
    ll t = T - (H[i] * 6);
    if (abs(A - t) < min_diff) {
      min_diff = abs(A - t);
      ans = i+1;
    }
  }
  cout << ans << endl;
  return 0;
}