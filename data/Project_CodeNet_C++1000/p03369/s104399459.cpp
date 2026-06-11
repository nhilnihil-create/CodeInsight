#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  cout << 700 + count(S.begin(), S.end(), 'o') * 100 << endl;
  return 0;
}