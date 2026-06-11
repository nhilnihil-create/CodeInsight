#include <iostream>

using namespace std;

int main () {
  int bh, bw, h, w;
  cin >> bh >> bw >> h >> w;
  cout << bh * bw - (h * bw + w * bh - h * w) << endl;
}