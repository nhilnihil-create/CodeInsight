/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc099_a.cpp
 * time   : Thu Apr 30 20:49:19 2020
 * quest  : A - ABD
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
  cout << ((n > 999) ? "ABD" : "ABC") << "\n";
  return 0;
}
