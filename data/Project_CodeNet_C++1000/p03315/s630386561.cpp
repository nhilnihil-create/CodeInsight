#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  int num = 0;
  rep(i, 4) {
    if (s.at(i) == '+') num++;
    else num--;
  }
  cout << num << endl;
}