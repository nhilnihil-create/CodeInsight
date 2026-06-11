/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc106_a.cpp
 * time   : Thu Apr 30 22:18:41 2020
 * quest  : A - Garden
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
  cout << (a * b) - (a + b - 1) << "\n";
  return 0;
}
