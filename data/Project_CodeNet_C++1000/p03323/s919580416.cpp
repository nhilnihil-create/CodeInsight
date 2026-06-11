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

  if (A > 8 || B > 8) {
    cout << ":(" << endl;
    return 0;
  }

  cout << "Yay!" << endl;  
  return 0;
}