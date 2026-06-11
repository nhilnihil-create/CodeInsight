/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc094_a.cpp
 * time   : Thu Apr 30 18:23:31 2020
 * quest  : A - Cats and Dogs
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
  int a, b, x;
  cin >> a >> b >> x;
  if (a > x)
    cout << "NO\n";
  else
    cout << ((a + b) >= x ? "YES" : "NO") << "\n";
  return 0;
}
