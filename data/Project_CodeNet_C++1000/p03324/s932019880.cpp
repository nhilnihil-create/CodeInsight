#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int func(int x) {
  if (x % 100 != 0) return 0;
  return func(x / 100) + 1;
}

int main() {
  int D, N;
  cin >> D >> N;
  int ans = 0;
  for (int i = 1;; i++) {
    if (func(i) == D) {
      ans++;
      if (ans == N) {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}
