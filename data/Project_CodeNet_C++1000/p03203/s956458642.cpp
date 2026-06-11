#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  
  vector<pair<int, int> > obstacle(N);
  map<pair<int, int>, bool> isObstacle;
  int x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    x--;
    y--;
    obstacle[i] = make_pair(y, x);
    isObstacle[make_pair(y, x)] = true;
  }
  sort(obstacle.begin(), obstacle.end());
  
  int counter = 0;
  int h = 0, w = 0;
  int best = H;
  while (true) {
    h++;
    if (h == H || isObstacle[make_pair(w, h)]) {
      best = min(best, h);
      break;
    }
    
    while(counter < N && obstacle[counter].first <= w) {
      int wObs = obstacle[counter].first;
      int hObs = obstacle[counter].second;
      // cout << w << " " << h << " " << wObs << " " << hObs << endl;
      if (wObs == w && hObs > h && best > hObs) {
        best = hObs;
      }
      counter++;
    }
    
    // cout << w + 1 << " " << h << endl;
    if (w + 1 < W && !isObstacle[make_pair(w + 1, h)]) {
      w++;
    }
  }
  
  cout << best << endl;

  return 0;
}
