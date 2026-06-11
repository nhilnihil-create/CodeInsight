#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int r, d, x;
  cin >> r >> d >> x;
  for (int i = 0; i < 10; i++) {
    cout << r * x - d << endl;
    x = r * x - d;
  }
  return 0;
}