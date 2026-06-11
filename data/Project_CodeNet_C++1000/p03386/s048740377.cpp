#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  for (int i = A; i <= min(B, A + K - 1); i++) cout << i << endl;
  for (int i = max(B - K + 1, A + K); i <= B; i++) cout << i << endl;
  return 0;
}
