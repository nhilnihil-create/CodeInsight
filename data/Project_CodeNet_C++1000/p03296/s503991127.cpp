#include <bits/stdc++.h>
#define sz(arr) (int)(arr).size()
#define rng(arr) arr.begin(), arr.end()
#define show(x) cout << #x << " = " << x << endl;

using namespace std;
typedef long long ll;

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

void Main() {
  Cin(int, n);
  Cins(int, n, a);

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      ans++;
      a[i] = -1;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  Main();
  return 0;
}