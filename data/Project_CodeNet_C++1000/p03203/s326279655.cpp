#include <iostream>
#include <set>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
  int H, W, N;
  cin >> H >> W;
  cin >> N;
  unordered_map<int, vector<int>> row_blocks;
  set<pair<int, int>> blocks;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    row_blocks[y].push_back(x);
    blocks.insert(make_pair(x, y));
  }

  for (int i = 0; i < W; i++) {
    if (row_blocks[i].size() > 0) {
      sort(row_blocks[i].begin(), row_blocks[i].end());
    }
    row_blocks[i].push_back(H);
  }

  int x = 0;
  int res = 1e9;
  for (int y = 0; y < W; y++) {
    int block_x = *upper_bound(row_blocks[y].begin(), row_blocks[y].end(), x);
    res = min(res, block_x);
    if (x + 1 == block_x) {
      break;
    } else {
      x++;
    }
    while (blocks.count(make_pair(x, y + 1)) && !blocks.count(make_pair(x, y))) {
      x++;
    }
    if (x >= H || blocks.count(make_pair(x, y))) {
      break;
    }
  }
  cout << res << endl;
  return 0;
}

