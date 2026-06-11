#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  ll s = INF, l = -INF;
  for (int i = 0; i < N; i++) {
    ll a;
    cin >> a;
    s = min(s, a);
    l = max(l, a);
  }
  cout << l - s << endl;
}
