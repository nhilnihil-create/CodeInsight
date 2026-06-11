#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int res = 0;
  for (int i = a; i <= b; i++) {
    string str = to_string(i);
    string rev = str;
    reverse(rev.begin(), rev.end());
    if (str == rev)
      ++res;
  }   
  cout << res << '\n';
  return 0;
}