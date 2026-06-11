#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  string S;
  cin >> S;

  bool ok = true;
  if (S.front() != 'A') {
    ok = false;
  }
  int count = 0;
  for (int i = 2; i < S.size() - 1; ++i) {
    if (S[i] == 'C') {
      count++;
    }
  }
  if (count != 1) {
    ok = false;
  }
  for (int i = 1; i < S.size(); ++i) {
    if (isupper(S[i]) && S[i] != 'C') {
      ok = false;
    }
  }

  if (ok) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
  
  return 0;
}