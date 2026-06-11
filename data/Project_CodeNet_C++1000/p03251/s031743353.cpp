#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;

  int mx = -100;
  rep(i, N)
  {
    int x;
    cin >> x;
    mx = std::max(mx, x);
  }

  int mn = 100;
  rep(i, M)
  {
    int y;
    cin >> y;
    mn = std::min(mn, y);
  }

  if (mx >= mn || mx >= Y || mn <= X)
  {
    cout << "War" << endl;
  }
  else
  {
    cout << "No War" << endl;
  }

  return 0;
}
