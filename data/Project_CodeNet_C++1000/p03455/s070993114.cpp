/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc086_a.cpp
 * time   : Thu Apr 30 16:12:44 2020
 * quest  : A - Product
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
  cout << ((a & 1) && (b & 1) ? "Odd" : "Even") << "\n";
  return 0;
}
