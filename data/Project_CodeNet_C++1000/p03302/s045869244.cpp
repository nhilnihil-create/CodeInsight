#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

// 4近傍、8近傍
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
  // 入力
  int a, b;
  cin >> a >> b;

  if (a + b == 15) {
    cout << "+" << endl;
  } else if (a * b == 15) {
    cout << "*" << endl;
  } else {
    cout << "x" << endl;
  }

  return 0;
}
