#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, a, b, c, d;
  cin >> H >> W;
  string str = "";
  for (int i = 0; i < H; i++){
    string line;
    cin >> line;
    str += line;
  }
  for (int i = 0; i < H; i++){
    if (i == 0){
      b = 1;
      if (H == 1){
        a = 1;
      }
      else
        a = 2;
    }
    else if (i == H - 1){
      a = 2;
      b = 0;
    }
    else{
      a = 3;
      b = 0;
    }
    for (int j = 0; j < W; j++){
      if (j == 0){
        d = 0;
        if (W == 1)
          c = 1;
        else
          c = 2;
      }
      else{
        d = 1;
        if (j == W - 1)
          c = 2;
        else
          c = 3;
      }
      if (j == W - 1){
        if (str.at(i * W + j) == '#')
          cout << "#" << endl;
        else{
          int count = 0;
          for (int k = 0; k < a; k++){
            for (int l = 0; l < c; l++){
              if (str.at((i - 1 + k + b) * W + j - d + l) == '#')
                count++;
            }
          }
          cout << count << endl;
        }
      }
      else if (str.at(i * W + j) == '#')
        cout << "#";
      else{
        int count = 0;
        for (int k = 0; k < a; k++){
          for (int l = 0; l < c; l++){
            if (str.at((i + k - 1 + b) * W + j + l - c + 2) == '#')
              count++;
          }
        }
        cout << count;
      }
    }
  }
}