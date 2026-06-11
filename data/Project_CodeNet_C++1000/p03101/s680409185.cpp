#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int H, W;
  cin >> H >> W;
  int h, w;
  cin >> h >> w;

  cout << (H - h) * (W - w) << endl;

  return 0;
}
