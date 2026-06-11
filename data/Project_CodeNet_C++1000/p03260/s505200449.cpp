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
  cin >> A >> B;

  for (int C = 1; C <= 3; ++C) {
    if ((A * B * C) % 2 != 0) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
 
  return 0;
}