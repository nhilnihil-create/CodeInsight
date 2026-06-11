#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto test = [&](long long x) {
    for (auto d : a) {
      x = x / d * d;
    }
    return x;
  };

  long long down, up;
  {
    long long l = 0, r = 5e16;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (test(m) >= 2) r = m;
      else l = m;
    }
    down = r;
  }
  {
    long long l = 0, r = 5e16;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (test(m) > 2) r = m;
      else l = m;
    }
    up = r;
  }

  if (down == up) {
    cout << -1 << '\n';
  } else {
    cout << down << ' ' << up - 1 << '\n';
  }
  return 0;
}
