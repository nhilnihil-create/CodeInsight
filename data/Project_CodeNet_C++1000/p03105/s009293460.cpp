/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc120_a.cpp
 * time   : Fri May  1 14:48:02 2020
 * quest  : A - Favorite Sound
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
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(c, b / a) << "\n";
  return 0;
}
