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
  string fes = "FESTIVAL";
  Cin(string, s);

  reverse(all(s));
  s.erase(0, sz(fes));
  reverse(all(s));

  puts(s.c_str());

  return 0;
}