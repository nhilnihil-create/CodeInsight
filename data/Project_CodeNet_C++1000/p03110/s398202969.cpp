#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<double, string>> m(n);
  for (int i = 0; i < n; i++) {
    cin >> m.at(i).first;
    cin >> m.at(i).second;
  }
  double res = 0;
  for (int i = 0; i < n; i++) {
    if (m.at(i).second == "JPY") {
      res += m.at(i).first;
    }
    else {
      res += m.at(i).first * 380000;
    }
  }
  cout << res << endl;
}
