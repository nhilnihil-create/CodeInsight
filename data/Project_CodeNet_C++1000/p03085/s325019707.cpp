/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc122_a.cpp
 * time   : Fri May  1 16:16:40 2020
 * quest  : A - Double Helix
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
  char ch;
  cin >> ch;
  cout << (ch == 'A' ? 'T' : (ch == 'T' ? 'A' : (ch == 'G' ? 'C' : 'G'))) << "\n";
  return 0;
}
