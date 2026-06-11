#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int A, B;
  string S;
  cin >> A >> B >> S;

  bool ok = true;
  for (int i = 0; i < A; ++i) {
    if (!isdigit(S[i])) ok = false;
  }
  if (S[A] != '-') ok = false;
  for (int i = A + 1; i < A + B + 1; ++i) {
    if (!isdigit(S[i])) ok = false;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}