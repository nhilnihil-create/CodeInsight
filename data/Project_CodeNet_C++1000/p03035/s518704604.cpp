#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int a, b;
  cin >> a >> b;
  if (a >= 13) {
    cout << b << endl;
    return 0;
  }
  if (a >= 6) {
    cout << b / 2 << endl;
    return 0;
  }
  cout << 0 << endl;
  return 0;
}