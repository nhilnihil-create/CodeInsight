#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string b;
  cin >> b;
  string ans;
  switch (b[0]) {
    case 'A':
      ans = "T";
      break;
    case 'C':
      ans = "G";
      break;
    case 'G':
      ans = "C";
      break;
    case 'T':
      ans = "A";
      break;
  }

  cout << ans << endl;
  return 0;
}
