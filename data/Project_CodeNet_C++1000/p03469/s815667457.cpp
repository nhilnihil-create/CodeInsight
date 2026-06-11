#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;

  string ans = "2018/01/" + s.substr(8);
  cout << ans << endl;
  return 0;
}