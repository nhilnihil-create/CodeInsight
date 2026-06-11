#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int D, N;
  cin >> D >> N;
  int ans = 1;
  for (int i = 0; i < D; i++) ans *= 100;
  int copy_ans = ans;
  ans *= N;
  if (N == 100) ans += copy_ans;
  cout << ans << endl;
}
