#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, a, b;
  cin >> n >> a >> b;
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    int sum = 0;
    for (auto c : s) {
      sum += c - '0';
    }
    
    if (a <= sum && sum <= b) {
      ans += i;
    }
  }

  cout << ans << '\n';
}
