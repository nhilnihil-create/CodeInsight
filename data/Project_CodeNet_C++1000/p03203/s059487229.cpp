#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define x first
#define y second

const int MAX_N = 2e5 + 5;

pair<int, int> obst [MAX_N];
vector<int> at [MAX_N];

int main () {
  int h, w;
  cin >> h >> w;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> obst[i].x >> obst[i].y;
    at[obst[i].x].push_back(obst[i].y);
  }

  int acc = 1;
  for (int i = 2; i <= h; i++) {
    // find out if there is an accessible endpiece
    for (int y : at[i]) {
      if (y <= acc) {
        cout << i - 1 << endl;
        return 0;
      }
    }

    int mny = w + 5;
    for (int y : at[i]) {
      mny = min(mny, y);
    }

    if (mny != acc + 1) {
      acc++;
    }
  }

  cout << h << endl;
}
