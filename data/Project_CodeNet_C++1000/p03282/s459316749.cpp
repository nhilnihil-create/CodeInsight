#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; long long k;
  cin >> s >> k;
  int cnt = 0;
  while(s[cnt] == '1' && cnt < (int)s.size()) {
    cnt++;
  }
  if (cnt == 0) {
    cout << s[0] << endl;
  } else if (cnt >= k) {
    cout << 1 << endl;
  } else {
    cout << s[cnt] << endl;
  }
  return 0;
}