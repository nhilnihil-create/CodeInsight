#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> board(H);
  vector<vector<int>> count(H, vector<int>(W));

  for(int i = 0; i < H; i++) {
    string line;
    cin >> line;
    int hPrev = i - 1;
    int hNext = i + 1;
    bool hPrevf = hPrev > -1;
    bool hNextf = hNext < H;
    for(int j = 0; j < W; j++) {
      if(line.at(j) != '#') {
        continue;
      }
      
      count.at(i).at(j) = -1;
      int prev = j - 1;
      int next = j + 1;
      bool prevf = prev > -1;
      bool nextf = next < W;
      if(prevf && count.at(i).at(prev) != -1) count.at(i).at(prev)++;
      if(nextf && count.at(i).at(next) != -1) count.at(i).at(next)++;
      if(hPrevf && count.at(hPrev).at(j) != -1) count.at(hPrev).at(j)++;
      if(hNextf && count.at(hNext).at(j) != -1) count.at(hNext).at(j)++;
      if(prevf && hPrevf && count.at(hPrev).at(prev) != -1) count.at(hPrev).at(prev)++;
      if(prevf && hNextf && count.at(hNext).at(prev) != -1) count.at(hNext).at(prev)++;
      if(nextf && hPrevf && count.at(hPrev).at(next) != -1) count.at(hPrev).at(next)++;
      if(nextf && hNextf && count.at(hNext).at(next) != -1) count.at(hNext).at(next)++;
    }
  }
  
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int a = count.at(i).at(j);

      if(a == -1) cout << '#';
      else cout << a;
    }
    cout << endl;
  }
}