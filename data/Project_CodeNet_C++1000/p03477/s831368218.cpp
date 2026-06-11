/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc083_a.cpp
 * time   : Thu Apr 30 00:33:02 2020
 * quest  : A - Libra
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
  cout << (((a + b) == (c + d)) ? "Balanced" : ((a + b) > (c + d)) ? "Left" : "Right") << "\n";
  return 0;
}
