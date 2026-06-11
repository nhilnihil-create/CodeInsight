#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int H, W;
vector<string> S;

void count_mine(int x, int y) {
  if (S[x][y] != '.') {
    cout << S[x][y];
    return;
  }

  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
      int u = x + i;
      int v = y + j;
      if (0 <= u && u < H && 0 <= v && v < W && S[u][v] == '#')
        count++;
    }
  }
  cout << count;
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    string s;
    cin >> s;
    S.push_back(s);
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      count_mine(i, j);
    }
    cout << endl;
  }

  return 0;
}
