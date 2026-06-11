#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int N;
  cin >> N;
  vector<int> p;
  p.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    ans += p[i];
  }
  ans += p.back() / 2;
  cout << ans << endl;
  return 0;
}