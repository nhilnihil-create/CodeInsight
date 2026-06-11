/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc078_a.cpp
 * time   : Wed Apr 29 22:39:04 2020
 * quest  : A - Hex
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
  char a, b;
  cin >> a >> b;
  cout << ((a == b) ? '=' : (a > b) ? '>' : '<') << "\n";
  return 0;
}
