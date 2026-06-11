#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()
#define all(arr) arr.begin(), arr.end()

using namespace std;

void _cin() {}
template <class Head, class... Tail>
void _cin(Head&& head, Tail&&... tail) {
  cin >> head;
  _cin(forward<Tail>(tail)...);
}

#define Cin(T, ...) \
  T __VA_ARGS__;    \
  _cin(__VA_ARGS__)

int main() {
  Cin(int, n, a, b);

  vector<bool> v1(n, false);
  vector<bool> v2(n, false);

  int max = 0;
  for (int i = 0; i < a; ++i) v1[i] = true;
  for (int i = 0; i < b; ++i) v2[i] = true;
  for (int i = 0; i < n; ++i) max += v1[i] && v2[i];

  int min = 0;
  reverse(all(v2));
  for (int i = 0; i < n; ++i) min += v1[i] && v2[i];

  printf("%d %d\n", max, min);

  return 0;
}