/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc111_a.cpp
 * time   : Fri May  1 02:04:42 2020
 * quest  : A - AtCoder Beginner Contest 999
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
  cout << (s[0] == '1' ? '9' : '1') << (s[1] == '1' ? '9' : '1') << (s[2] == '1' ? '9' : '1') << "\n";
  return 0;
}
