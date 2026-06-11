#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a, b, n, h, w;
  cin >> a >> b;
  a--;
  b--;
  n = max(a, b) / 50 + 1;
  
  h = 4 * n;
  w = 100;
  cout << h << " " << w << endl;
  
  rep(j, n) {
    if (a > 50) {
      rep(i, 50) { cout << ".#"; }
      a -= 50;
    } else {
      rep(i, a) { cout << ".#"; }
      rep(i, 50-a) { cout << "##"; }
      a = 0;
    }
    cout << endl;
    rep(i, w) { cout << "#"; }
    cout << endl;
  }
  
  rep(j, n) {
    rep(i, w) { cout << "."; }
    cout << endl;
    if (b > 50) {
      rep(i, 50) { cout << "#."; }
      b -= 50;
    } else {
      rep(i, b) { cout << "#."; }
      rep(i, 50-b) { cout << ".."; }
      b = 0;
    }
    cout << endl;
  }
  
  
}
