#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  
  vector<int> va(n);
  for (auto &a : va) {
  	cin >> a;
  }
  
  int ans = 0;
  for (auto &a : va) {
    while (a != 0 && a % 2== 0) {
      a /= 2;
      ans++;
    }
  }
  
  cout << ans << '\n';
  return 0;
}