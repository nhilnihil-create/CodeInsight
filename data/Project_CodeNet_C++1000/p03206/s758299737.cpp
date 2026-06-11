/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc115_a.cpp
 * time   : Fri May  1 14:24:11 2020
 * quest  : A - Christmas Eve Eve Eve
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
  int d;
  cin >> d;
  cout << ((d > 24) ? "Christmas\n" : (d > 23) ? "Christmas Eve\n" : (d > 22) ? "Christmas Eve Eve\n" : "Christmas Eve Eve Eve\n");
  return 0;
}
