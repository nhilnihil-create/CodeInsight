#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  if ((S[0] == S[1] && S[1] == S[2]) || (S[1] == S[2] && S[2] == S[3]))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}