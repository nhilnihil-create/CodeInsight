#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  string X;
  cin >> X;

  int fX = 0;
  rep(i, X.size()) fX += X[i] - '0';
  string ans;
  if ((stoi(X) % fX) == 0) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return 0;
}