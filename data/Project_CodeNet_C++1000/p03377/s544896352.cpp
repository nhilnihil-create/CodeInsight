#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int A, B, X;
  cin >> A >> B >> X;

  int c = X - A;
  if (c >= 0 && c <= B) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}