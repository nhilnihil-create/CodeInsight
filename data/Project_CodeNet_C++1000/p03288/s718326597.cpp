/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc104_a.cpp
 * time   : Thu Apr 30 21:55:52 2020
 * quest  : A - Rated for Me
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
  int r;
  cin >> r;
  cout << (r < 1200 ? "ABC" : r < 2800 ? "ARC" : "AGC") << "\n";
  return 0;
}
