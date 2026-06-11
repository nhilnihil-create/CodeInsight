#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int ans = 0;
  while (true) {
    int ok = all_of(va.begin(), va.end(), [] (int a) { return a % 2 == 0; });
    if (!ok) {
      break;
    }
    
    for (auto &a : va) {
      a /= 2;
    }
    
    ans++;
  }

  cout << ans << '\n';
}