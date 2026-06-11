/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc101_a.cpp
 * time   : Thu Apr 30 21:36:14 2020
 * quest  : A - Eating Symbols Easy
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
  cout << 0 + (s[0] == '-' ? -1 : 1) + (s[1] == '-' ? -1 : 1) + (s[2] == '-' ? -1 : 1) + (s[3] == '-' ? -1 : 1) << "\n";
  return 0;
}
