/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc077_a.cpp
 * time   : Wed Apr 29 22:34:26 2020
 * quest  : A - Rotation
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
  char a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (f == a && e == b && c == d)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
