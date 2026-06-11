#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,h,w;

  cin >> H >> W >> h >> w;

  int whiteCells = (H - h)*(W - w);

  cout << whiteCells;
  
  return 0;
}