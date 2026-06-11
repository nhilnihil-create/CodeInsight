/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc096_a.cpp
 * time   : Thu Apr 30 18:35:37 2020
 * quest  : A - Day of Takahashi
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
  int a, b;
  cin >> a >> b;
  cout << ((b >= a) ? a : a - 1) << "\n";
  return 0;
}
