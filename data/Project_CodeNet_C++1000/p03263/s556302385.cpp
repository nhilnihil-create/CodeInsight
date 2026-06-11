#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  int coin[510][510];
  
  for (int i = 1; i <= H; i++) { 
    for (int j = 1; j <= W; j++) {
      cin >> coin[i][j];
    }
  } 
  
  vector<int> memo;
  for (int i = 1; i <= H; i++) {
    if (i % 2) {
      for (int j = 1; j <= W; j++) {
        if(j <= W-1 && (coin[i][j] % 2 == 1)) {
          coin[i][j]--;
          coin[i][j+1]++;
          
          memo.push_back(i);
          memo.push_back(j);
          memo.push_back(i);
          memo.push_back(j+1);
        } else if (i < H && j == W && (coin[i][j] % 2 == 1)){
          coin[i][j]--;
          coin[i+1][j]++;
          memo.push_back(i);
          memo.push_back(j);
          memo.push_back(i+1);
          memo.push_back(j);
        }
      }
    } else {
      for (int j = W; j >= 1; j--) {
        if (j >= 2 && (coin[i][j] % 2 == 1)) {
          coin[i][j]--;
          coin[i][j-1]++;
          memo.push_back(i);
          memo.push_back(j);
          memo.push_back(i);
          memo.push_back(j-1);
        } else if (i < H && j == 1 && (coin[i][j] % 2 == 1)) {
          coin[i][j]--;
          coin[i+1][j]++;
          memo.push_back(i);
          memo.push_back(j);
          memo.push_back(i+1);
          memo.push_back(j);
        }
      }
    }
  }
  
  cout << memo.size() / 4 << endl;
  
  for (int i = 0; i < memo.size() / 4; i++) {
    cout << memo[4 * i] << " " << memo[4 * i+1] << " " <<
    memo[4 * i + 2] << " " << memo[4 * i + 3];
    cout << endl;
  }
  
}