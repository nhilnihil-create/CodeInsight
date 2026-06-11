/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc116_a.cpp
 * time   : Fri May  1 14:31:27 2020
 * quest  : A - Right Triangle
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
  int ab, bc, ca;
  cin >> ab >> bc >> ca;
  cout << (ab * bc * ca) / (max(ab, max(bc, ca)) * 2) << "\n";
  return 0;
}
