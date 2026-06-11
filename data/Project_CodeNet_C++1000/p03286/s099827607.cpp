#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N;
  cin >> N;

  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> S;
  long long now = 0;
  long long m = 2;
  long long k = 1;
  while (now != N) {
    int s = (N - now) % m != 0;
    S.push_back(s);
    if (s) now += k;
    m *= 2;
    k *= -2;
  }
  int sz = S.size();
  for (int i = sz - 1; i >= 0; i--) {
    cout << S[i];
  }
  cout << endl;

  return 0;
}
/* vim:set fdm=marker: */
