#include <bits/stdc++.h>
using namespace std;
#define sw(c) (c == '1' ? 9 : 1)
int main() {
  string s;
  cin >> s;
  cout << sw(s[0]) * 100 + sw(s[1]) * 10 + sw(s[2]);
}
