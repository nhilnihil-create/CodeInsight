#include <bits/stdc++.h>
using namespace std;


using Coordinate = pair<int, int>;


int solve(int h, int w, vector<string> grid) {
  vector<Coordinate> d;
  d.push_back(Coordinate(-1, 0));
  d.push_back(Coordinate(1, 0));
  d.push_back(Coordinate(0, -1));
  d.push_back(Coordinate(0, 1));

  queue<Coordinate> q;
  vector< vector<int> > n_step(h, vector<int>(w));

  for (int ih = 0; ih < h; ih++) {
    for (int iw = 0; iw < w; iw++) {
      if (grid[ih][iw] == '#') {
        q.push(make_pair(ih, iw));
        n_step[ih][iw] = 1;
      }
    }
  }

  while (!q.empty()) {
    Coordinate c0 = q.front();
    q.pop();
    int ih0 = c0.first;
    int iw0 = c0.second;
    int n = n_step[ih0][iw0];

    for (int i = 0; i < 4; i++) {
      int ih1 = ih0 + d[i].first;
      int iw1 = iw0 + d[i].second;

      if (ih1 < 0) continue;
      if (ih1 >= h) continue;
      if (iw1 < 0) continue;
      if (iw1 >= w) continue;

      if (n_step[ih1][iw1] == 0) {
        n_step[ih1][iw1] = n + 1;
        q.push(Coordinate(ih1, iw1));
      }
    }
  }

  int m = 0;
  for (int ih = 0; ih < h; ih++) {
    for (int iw = 0; iw < w; iw++) {
      m = max(m, n_step[ih][iw]);
    }
  }

  return m - 1;
}

int main() {
  /* int h, w; */
  /* h = 3; */
  /* w = 3; */
  /* vector<string> grid(h); */
  /* grid[0] = "..."; */
  /* grid[1] = ".#."; */
  /* grid[2] = "..."; */

  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for (int ih = 0; ih < h; ih++) cin >> grid[ih];

  int answer = solve(h, w, grid);
  cout << answer << endl;
}
