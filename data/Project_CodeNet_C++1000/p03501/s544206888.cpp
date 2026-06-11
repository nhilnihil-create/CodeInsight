/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc080_a.cpp
 * time   : Wed Apr 29 22:56:37 2020
 * quest  : A - Parking
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
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(n * a, b) << "\n";
  return 0;
}
