#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if ((abs(a-b) <= d && abs(c-b) <= d) || abs(a-c) <= d) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
