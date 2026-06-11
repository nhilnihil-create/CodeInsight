#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str.at(i) == '2') {
      ans++;
    }
  }
  cout << ans << endl;
}
