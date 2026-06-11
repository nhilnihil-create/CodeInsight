#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int X;
  cin >> X;
  vector<bool> expo(X + 1);

  expo[1] = true;
  repe(b, 2, X) {
    int v = b * b;
    while (v <= X) {
      expo[v] = true;
      v *= b;
    }
  }

  for (int i = X; i >= 1; i--) {
    if (!expo[i]) continue;
    cout << i << endl;
    return 0;
  }
}
