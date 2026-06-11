/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc097_a.cpp
 * time   : Thu Apr 30 18:44:27 2020
 * quest  : A - Colorful Transceivers
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (abs(c - a) <= d ? "Yes" : (abs(b - a) <= d && abs(c - b) <= d) ? "Yes" : "No") << "\n";
  return 0;
}
