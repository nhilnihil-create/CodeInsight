/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc110_a.cpp
 * time   : Thu Apr 30 22:44:06 2020
 * quest  : A - Maximize the Formula
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
  cout << max(a, max(b, c)) * 10 + (a + b + c - max(a, max(b, c))) << "\n";
  return 0;
}
