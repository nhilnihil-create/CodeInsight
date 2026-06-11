/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc121_a.cpp
 * time   : Fri May  1 16:11:55 2020
 * quest  : A - White Cells
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
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  cout << (H - h) * (W - w) << "\n";
  return 0;
}
