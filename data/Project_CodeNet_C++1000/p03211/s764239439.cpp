#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  string S;
  cin >> S;
  
  int ans = 1000;
  for (int i = 0; i + 2 < S.size(); i++) {
    int n = stoi(S.substr(i, 3));
    ans = min(ans, abs(n - 753));
  }
  cout << ans << endl;
  return 0;
}