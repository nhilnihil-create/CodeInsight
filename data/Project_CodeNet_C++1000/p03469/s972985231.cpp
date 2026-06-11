/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc085_a.cpp
 * time   : Thu Apr 30 16:09:47 2020
 * quest  : A - Already 2018
 *********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (i == 3)
      cout << '8';
    else
      cout << s[i];
  }
  cout << "\n";
  return 0;
}
