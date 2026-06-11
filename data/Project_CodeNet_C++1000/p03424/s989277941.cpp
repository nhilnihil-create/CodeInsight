#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  bool x = false;
  cin >> N;

  // ここにプログラムを追記
  rep (i, N) {
    string S = "";
    cin >> S;
    if (S == "Y") {
      x = true;
      break;
    }
  }
  if (x) {
    cout << "Four" << endl;
  } else {
    cout << "Three" << endl;
  }
}
