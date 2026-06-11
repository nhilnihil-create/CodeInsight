//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  int n;
  cin >> n;
  vector<int> alll(n), odd(n);
  rep(i, n) {
    int a;
    cin >> a;
    for (int j = -1; j <= 1; j++) {
      if (a+j < 0) continue;
      if ((a+j) % 2 == 0) {
        alll[i]++;
      } else {
        alll[i]++;
        odd[i]++;
      }
    }
  }
  int a1 = 1, a2 = 1;
  rep(i, n) {
    a1 *= alll[i];
    a2 *= odd[i];
  }
  cout << a1 - a2 << endl;
  return 0;
}