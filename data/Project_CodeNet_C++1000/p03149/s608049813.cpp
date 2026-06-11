#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> n(4);
  for (int i=0; i<4; i++) cin >> n[i];
  sort(n.begin(), n.end());
  string ans = "YES";
  if (n[0] != 1 || n[1] != 4 || n[2] != 7 || n[3] != 9) ans = "NO";
  cout << ans << endl;
  return 0;
}
