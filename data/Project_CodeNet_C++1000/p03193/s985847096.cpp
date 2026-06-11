#include <iostream>

using namespace std;

int main()
{
  int N, H, W;
  cin >> N >> H >> W;
  int r = 0;
  while (N--) {
    int h, w;
    cin >> h >> w;
    if (H <= h && W <= w) r++;
  }
  cout << r << endl;
}