#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;
  vector<std::pair<int, int>> red(N);
  vector<std::pair<int, int>> blue(N);

  int a, b;
  rep(i, N) {
    cin >> a >> b;
    red[i] = std::make_pair(a, b);
  }
  rep(i, N) {
    cin >> a >> b;
    blue[i] = std::make_pair(a, b);
  }

  std::sort(blue.begin(), blue.end());

  int sum = 0;
  rep(i, N) {
    int x1 = blue[i].first;
    int y1 = blue[i].second;
  
    int dist = 2 * N;
    int pos = -1;
    rep(j, red.size()) {
      int x2 = red[j].first;
      int y2 = red[j].second;

      int dist2 = std::abs(y1-y2);
      if (x1 > x2 && y1 > y2 && dist > dist2) {
        pos = j;
        dist = dist2;
      }
    }

    if (pos != -1) {
      sum++;
      red.erase(red.begin() + pos);
    }
  }

  cout << sum << endl;

  return 0;
}
