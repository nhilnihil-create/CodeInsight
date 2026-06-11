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
  int N, K;
  cin >> N >> K;

  vector<int> h(N);
  rep(i, N) cin >> h[i];

  std::sort(h.begin(), h.end());
  int mn = 1000000000;
  rep(i, N - (K - 1))
  {
    int diff = h[i + K - 1] - h[i];
    if (mn > diff)
      mn = diff;
  }

  cout << mn << endl;

  return 0;
}
