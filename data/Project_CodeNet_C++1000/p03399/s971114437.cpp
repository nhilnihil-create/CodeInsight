/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc092_a.cpp
 * time   : Thu Apr 30 18:15:53 2020
 * quest  : A - Traveling Budget
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(a, b) + min(c, d) << "\n";
  return 0;
}