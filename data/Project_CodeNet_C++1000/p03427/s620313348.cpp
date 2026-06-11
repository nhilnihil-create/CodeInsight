#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string n;
  cin >> n;
  int sum = n[0] - '0';
  for (int i = 1; i < n.size(); ++i) {
    if (n[i] != '9') {
      sum--;
      sum += 9 * (n.size() - i);
      break;
    }
    sum += 9;
  }
  cout << sum << endl;
  return 0;
}