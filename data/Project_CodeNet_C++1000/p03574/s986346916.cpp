#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, count;
  string X, Y;
  cin >> H >> W >> X;
  for (int i = 0; i < H; i++){
    cin >> Y;
    X += Y;
  }
  for (int i = 0; i < H * W; i++){
    count = 0;
    if (i >= W && i % W == 0)
      cout << endl;
    if (X.at(i) == '#'){
      cout << "#";
      continue;
    }
    else{
      if (i > W && i % W != 0){
        if (X.at(i - W - 1) == '#'){
          count++;
        }
      }
      if (i >= W){
        if (X.at(i - W) == '#'){
          count++;
        }
      }
      if (i >= W && i % W != W - 1){
        if (X.at(i - W + 1) == '#'){
          count++;
        }
      }
      if (i % W != 0){
        if (X.at(i - 1) == '#'){
          count++;
        }
      }
      if (i % W != W - 1){
        if (X.at(i + 1) == '#'){
          count++;
        }
      }
      if (i < (H - 1) * W && i % W != 0){
        if (X.at(i + W - 1) == '#'){
          count++;
        }
      }
      if (i < (H - 1) * W){
        if (X.at(i + W) == '#'){
          count++;
        }
      }
      if (i < (H - 1) * W && i % W != W - 1){
        if (X.at(i + W + 1) == '#'){
          count++;
        }
      }
      cout << count;
    }
  }
}