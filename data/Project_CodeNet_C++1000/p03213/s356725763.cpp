#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int prime[101];
  for (int i = 0; i < 101; i++) {
    prime[i] = 0;
  } 
  for (int i = 2; i <= N; i++) {
    int num = i;
    for (int j = 2; j <= i; j++) {
      while (num % j == 0) {
        num /= j;
        prime[j]++;
      }
    }
  }
  int _74 = 0;
  int _24 = 0;
  int _4 = 0;
  int _14 = 0;
  int _2 = 0;
  for (int i = 0; i < 101; i++) {
    if (prime[i] >= 74) {
      _74++;
    }
    if (prime[i] >= 4) {
      _4++;
    }
    if (prime[i] >= 2) {
      _2++;
    }
    if (prime[i] >= 14) {
      _14++;
    }
    if (prime[i] >= 24) {
      _24++;
    }
  }
  int ans = 0;
  ans += _74;
  ans += _24 * (_2 - 1);
  ans += _14 * (_4 - 1);
  ans += (_4 * (_4 - 1) / 2) * (_2 - 2);
  cout << ans << endl;
  return 0;
}