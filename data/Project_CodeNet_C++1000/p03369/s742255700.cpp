#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  int num = 0;
  rep(i, 3) {
    if (s.at(i) == 'o') num++;
  }
  cout << 700 + num * 100 << endl;
}