#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  int a,b;
  cin >> a >> b;
  if (a > b) {
    cout << a - 1 << endl;
  } else {
    cout << a << endl;
  }
}
