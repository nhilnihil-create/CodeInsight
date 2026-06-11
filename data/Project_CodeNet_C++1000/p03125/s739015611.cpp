/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc118_a.cpp
 * time   : Fri May  1 14:42:02 2020
 * quest  : A - B +/- A
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
  cout << ((b % a) ? b - a : a + b) << "\n";
  return 0;
}
