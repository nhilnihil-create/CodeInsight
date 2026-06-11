/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc109_a.cpp
 * time   : Thu Apr 30 22:39:21 2020
 * quest  : A - ABC333
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
  cout << ((a * b) % 2 ? "Yes" : "No") << "\n";
  return 0;
}
