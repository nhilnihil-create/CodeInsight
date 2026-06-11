#include <bits/stdc++.h>
#define sz(arr) (int)(arr).size()
#define rng(arr) arr.begin(), arr.end()
#define show(x) cout << #x << " = " << x << endl;

using namespace std;
typedef long long int ll;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

#define Cins(T, n, xs) \
  vector<T> xs(n);     \
  for (int i = 0; i < n; ++i) cin >> xs[i]

void Main();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  Main();
  return 0;
}

void Main() {
  Cin(int, n, a, b);

  bool wina = false, winb = false;
  while (!wina && !winb) {
    if (a + 1 != b)
      a++;
    else {
      a--;
      if (a == 0) winb = true;
    }
    if (b - 1 != a)
      b--;
    else {
      b++;
      if (b == n + 1) wina = true;
    }
  }

  cout << (wina ? "Alice" : "Borys") << endl;
}