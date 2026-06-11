/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc091_a.cpp
 * time   : Thu Apr 30 18:11:25 2020
 * quest  : A - Two Coins
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
  cout << ((a + b) >= c ? "Yes" : "No") << "\n";
  return 0;
}
