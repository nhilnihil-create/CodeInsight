#include <iostream>
#include <vector>


using namespace std;


void white_cells()
{
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  cout << (H * W) - (h * W) - (H * w) + (h * w) << "\n";
}


int main()
{
  white_cells();
}