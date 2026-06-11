#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  int cnt0 = count(S.begin(), S.end(), '0');
  int cnt1 = count(S.begin(), S.end(), '1');

  cout << 2 * min(cnt0, cnt1) << endl;
  return 0;
}