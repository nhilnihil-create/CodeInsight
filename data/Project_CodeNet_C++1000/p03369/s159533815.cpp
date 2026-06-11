/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc095_a.cpp
 * time   : Thu Apr 30 18:30:54 2020
 * quest  : A - Something on It
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
  cout << 700 + (s[0] == 'o' ? 100 : 0) + (s[1] == 'o' ? 100 : 0) + (s[2] == 'o' ? 100 : 0) << "\n";
  return 0;
}
