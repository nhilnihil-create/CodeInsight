#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string answer = "No";
  for (int i = 0; i <= n / 4; i++) {//cake4ドル * i個
    if ((n - 4 * i) % 7 == 0) {
      answer = "Yes";
      break;
    }
  }
  cout << answer;
}