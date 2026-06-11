/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc124_a.cpp
 * time   : Fri May  1 16:38:09 2020
 * quest  : A - Buttons
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
  cout << max(a + b, max(a, b) + max(a, b) - 1) << "\n";
  return 0;
}
