/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc075_a.cpp
 * time   : Wed Apr 29 15:52:58 2020
 * quest  : A - One out of Three
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
  cout << (a ^ b ^ c) << "\n";
  return 0;
}
