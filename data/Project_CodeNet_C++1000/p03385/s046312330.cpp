#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  if (count(S.begin(), S.end(), 'a') == 1 &&
      count(S.begin(), S.end(), 'b') == 1 &&
      count(S.begin(), S.end(), 'c') == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}