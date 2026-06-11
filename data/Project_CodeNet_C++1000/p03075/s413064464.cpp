/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc123_a.cpp
 * time   : Fri May  1 16:21:04 2020
 * quest  : A - Five Antennas
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
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  cout << ((b - a <= k && c - a <= k && d - a <= k && e - a <= k && c - b <= k && d - b <= k && e - b <= k && d - c <= k && e - c <= k && e - d <= k) ? "Yay!\n" : ":(\n");
  return 0;
}
