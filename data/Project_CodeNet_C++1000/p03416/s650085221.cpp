#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  string s1, s2;
  for (int n = a; n < b+1; n++) {
    s1 = to_string(n);
    s2 = s1;
    reverse(s1.begin(), s1.end());
    if (s1 == s2) {
      ans++;
    }
  }
  cout << ans << endl;
}