#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  if (S.size() == 2)
    cout << S << endl;
  else {
    reverse(S.begin(), S.end());
    cout << S << endl;
  }
  return 0;
}