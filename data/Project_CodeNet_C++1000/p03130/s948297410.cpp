#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0, x;
  vector<ll> a(4, 0);
  rep(i, 6) cin >> x, x--, a[x]++;
  int one = 0, two = 0, three = 0, four = 0;
  for (auto b : a) {
    if (b != 2 && b != 1) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");
  return 0;
}
