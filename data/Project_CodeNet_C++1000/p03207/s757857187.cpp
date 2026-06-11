#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n; cin >> n;
  vector<int> s(n);
  for (int i=0; i<n; i++) cin >> s.at(i);
  sort(s.begin(), s.end());
  
  int ans = 0;
  for (int i=0; i<(n-1); i++) {
    ans += s[i];
  }
  
  ans += s[n-1] / 2;
  cout << ans << endl;
  return 0;
}