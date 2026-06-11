/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc105_a.cpp
 * time   : Thu Apr 30 21:59:27 2020
 * quest  : A - AtCoder Crackers
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
  int n, k;
  cin >> n >> k;
  cout << ((n % k) ? 1 : 0) << "\n";
  return 0;
}
