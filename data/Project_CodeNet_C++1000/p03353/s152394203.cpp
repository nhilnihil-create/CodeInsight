#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;

  vector<string> sub;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 1; j <= 5; ++j) {
      sub.push_back(s.substr(i, j));
    }
  }
  sort(sub.begin(), sub.end());
  unique(sub.begin(), sub.end());

  cout << sub[k - 1] << endl;
  return 0;
}
