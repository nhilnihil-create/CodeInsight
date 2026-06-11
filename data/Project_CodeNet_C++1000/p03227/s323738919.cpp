#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n == 2) {
    cout << s << '\n';
  } else {
    reverse(s.begin(), s.end());
    cout << s << '\n';
  }
  return 0;
}
