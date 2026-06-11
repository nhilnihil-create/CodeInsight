#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int cnt = 1, mx = 1;
  for(int i = 1; i < n; i++) {
    if(s[i-1] == s[i]) {
      cnt++;
      mx = max(mx, cnt);
    } else {
      cnt = 1;
    }
  }
  if(mx >= 3) cout << "Yes" << endl;
  else cout << "No" << endl;
}
