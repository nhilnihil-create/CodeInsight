/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc103_a.cpp
 * time   : Thu Apr 30 21:43:50 2020
 * quest  : A - Task Scheduling Problem
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
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(a, max(b, c)) - min(a, min(b, c)) << "\n";
  return 0;
}
