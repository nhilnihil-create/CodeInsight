/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc125_a.cpp
 * time   : Fri May  1 16:41:40 2020
 * quest  : A - Biscuit Generator
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
  int a, b, t;
  cin >> a >> b >> t;
  cout << (t / a * b) << "\n";
  return 0;
}
