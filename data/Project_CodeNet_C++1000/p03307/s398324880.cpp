/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc102_a.cpp
 * time   : Thu Apr 30 21:42:07 2020
 * quest  : A - Multiple of 2 and N
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
  int n;
  cin >> n;
  cout << (n % 2 ? n * 2 : n) << "\n";
  return 0;
}
