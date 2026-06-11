#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<map<int, int>> cnt_map(2);
  for (int n = 0; n < N; ++n) {
    int v;
    cin >> v;
    ++cnt_map[n % 2][v];
  }
  vector<vector<pair<int, int>>> cnts(2, vector<pair<int, int>>(2, {0, 0}));
  for (int i = 0; i < 2; ++i) {
    for (const auto& p : cnt_map[i]) {
      if (p.second >= cnts[i][0].second) {
        cnts[i][1] = cnts[i][0];
        cnts[i][0] = p;
      } else if (p.second >= cnts[i][1].second) {
        cnts[i][1] = p;
      }
    }
  }
  if (cnts[0][0].first == cnts[1][0].first) {
    int res = max(cnts[0][0].second + cnts[1][1].second,
                  cnts[0][1].second + cnts[1][0].second);
    cout << N - res << endl;
  } else {
    cout << N - cnts[0][0].second - cnts[1][0].second << endl;
  }
      
  return 0;
}
