#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<int> o(H * W, 0);
  vector<char> data(H * W);
  for (int i = 0; i < H * W; i++) {
  cin >> data.at(i);
  }
  
  for (int i = 0; i < H * W; i++) {
    if (data.at(i) == '#') {
      if (i % W != 0 && i > W && data.at(i - W - 1) != '#') o.at(i - W - 1)++;
      if (i > W - 1 && data.at(i - W) != '#') o.at(i - W)++;
      if (i % W != W - 1 && i > W - 1 && data.at(i - W + 1) != '#') o.at(i - W + 1)++;
      if (i % W != 0 && i > 0 && data.at(i - 1) != '#') o.at(i - 1)++;
      if (i % W != W - 1 && i < H * W - 1 && data.at(i + 1) != '#') o.at(i + 1)++;
      if (i % W != 0 && i < H * W - W && data.at(i + W - 1) != '#') o.at(i + W - 1)++;
      if (i < H * W - W && data.at(i + W) != '#') o.at(i + W)++;
      if (i % W != W - 1 && i < H * W - W - 1 && data.at(i + W + 1) != '#') o.at(i + W + 1)++;
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i * W + j) == '#') {
        cout << data.at(i * W + j);
      }
      else {
        cout << o.at(i * W + j);
      }
    }
    cout << endl;
  }
}