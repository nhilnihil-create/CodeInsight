#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> coin(h, vector<int>(w));
  for (int i=0; i<h; ++i) {
    for (int j=0; j<w; ++j) {
      cin >> coin.at(i).at(j);
    }
  }
  
  vector<vector<int>> res;
  int pi = 0, pj = 0;
  for (int i=0; i<h; ++i) {
    if (i%2 == 0) {
      for (int j=0; j<w; ++j) {
        if (i == 0 && j == 0) continue;
        if (coin.at(pi).at(pj) %2 != 0) {
          coin.at(i).at(j)++;
          res.push_back({pi+1, pj+1, i+1, j+1});
        }
        pi = i, pj = j;
      }
    } else {
      for (int j=w-1; j>=0; --j) {
        if (coin.at(pi).at(pj) %2 != 0) {
          coin.at(i).at(j)++;
          res.push_back({pi+1, pj+1, i+1, j+1});
        }
        pi = i;
        pj = j;
      }
    }
  }
  
  cout << (int)res.size() << endl;
  for (auto v : res) {
    cout << v.at(0) << ' ' << v.at(1) << ' ' << v.at(2) << ' ' << v.at(3) << endl;
  }
  return 0;
}
