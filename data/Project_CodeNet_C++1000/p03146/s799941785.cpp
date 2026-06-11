#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int s;
  cin >> s;

  vector<bool> used(1000009, false);
  int m;
  for (m = 1; m < 1000009; ++m) {
    if (used[s] == true) break;
    used[s] = true;
    if (s % 2 == 0) s /= 2;
    else s = 3 * s + 1;
  }
  cout << m << endl;
  return 0;
}