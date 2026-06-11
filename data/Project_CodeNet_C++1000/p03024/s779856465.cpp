#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  if (count(S.begin(), S.end(), 'o') + (15 - S.size()) >= 8)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}