/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc093_a.cpp
 * time   : Thu Apr 30 18:18:12 2020
 * quest  : A - abc of ABC
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
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  cout << (s == "abc" ? "Yes" : "No") << "\n";
  return 0;
}
