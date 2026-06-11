/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc108_a.cpp
 * time   : Thu Apr 30 22:25:55 2020
 * quest  : A - Pair
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
  int k;
  cin >> k;
  cout << ((k % 2) ? (k / 2 * (k / 2 + 1)) : (k / 2 * k / 2)) << "\n";
  return 0;
}
