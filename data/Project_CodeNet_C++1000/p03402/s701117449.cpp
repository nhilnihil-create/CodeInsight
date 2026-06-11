#include <bits/stdc++.h>
#define N 100
using namespace std;
bool valid_neighbours(string *grid, int x, int y, char c) {
  if (x && grid[x-1][y] == c) {
    return false;
  }
  if (x && y && grid[x-1][y-1] == c) {
    return false;
  }
  if (x && y+1 < N && grid[x-1][y+1] == c) {
    return false;
  }
  if (y && grid[x][y-1] == c) {
    return false;
  }
  if (y+1 < N && grid[x][y+1] == c) {
    return false;
  }
  if (x+1 < N && y && grid[x+1][y-1] == c) {
    return false;
  }
  if (x+1 < N && grid[x+1][y] == c) {
    return false;
  }
  if (x+1 < N && y+1 < N && grid[x+1][y+1] == c) {
    return false;
  }
  return true;
}
void place_white(string *grid, int C) {
  for (int i = 0; i < N/2-1; i++) {
    for (int j = 0; j < N; j++) {
      if (C == 1) {
        return;
      }
      if (valid_neighbours(grid,i,j,'.')) {
        grid[i][j] = '.';
        C--;
      }
    }
  }
}
void place_black(string *grid, int C) {
  for (int i = N-1; i > N/2; i--) {
    for (int j = 0; j < N; j++) {
      if (C == 1) {
        return;
      }
      if (valid_neighbours(grid,i,j,'#')) {
        grid[i][j] = '#';
        C--;
      }
    }
  }
}
int main() {
  string grid[N];
  int A,B;
  cin >> A >> B;
  for (int i = 0; i < N/2; i++) {
    grid[i] = string(N,'#');
  }
  for (int i = N/2; i < N; i++) {
    grid[i] = string(N,'.');
  }
  cout << N << ' ' << N << endl;
  place_white(grid,A);
  place_black(grid,B);
  for (int i = 0; i < N; i++) {
    cout << grid[i] << endl;
  }
}