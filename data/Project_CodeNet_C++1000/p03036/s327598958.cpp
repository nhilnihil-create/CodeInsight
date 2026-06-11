#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1000000007;

int main() {
  int r, d, x;
  cin >> r >> d >> x;
  ll now = x;
  for (int i = 1; i <= 10; i++) {
    now *= r;
    now -= d;
    cout << now << endl;
  }
}
