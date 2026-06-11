#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<int>> changeNum(10, vector<int>(10));
vector<vector<int>> wall(201, vector<int>(201));
vector<int> toOne(10, 999999999);

void searchMin(int k, vector<bool> check, int sum, int pre) {
  if (toOne[pre] > sum) {
    toOne[pre] = sum;
  }
  if (k == 9) {
    return;
  }
  for (int i = 0; i < 10; i++) {
    if (check[i]) {
      continue;
    }
    check[i] = true;
    searchMin(k + 1, check, sum + changeNum[i][pre], i);
    check[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> H >> W;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> changeNum[i][j];
    }
  }
  vector<bool> check(10);
  check[1] = true;
  toOne[1] = 0;
  long long sum = 0;
  searchMin(0, check, sum, 1);
  long long ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> wall[i][j];
      if(wall[i][j] != -1){
        ans += toOne[wall[i][j]];
      }
    }
  }
  cout << ans <<endl;
}
