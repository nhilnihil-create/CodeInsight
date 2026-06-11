#include <iostream>
#include <vector>

using namespace std;

const int grid_num = 3;

int main() {
  vector<vector<int>> grid(grid_num + 1, vector<int>(grid_num + 1, -1));

  for(int i = 1; i <= grid_num; i++) {
    for(int j = 1; j <= grid_num; j++) {
      cin >> grid[i][j];
    }
  }

  // a1 - a2
  bool can = true;
  if(grid[1][1] - grid[2][1] != grid[1][2] - grid[2][2] ||
    grid[1][2] - grid[2][2] != grid[1][3] - grid[2][3]) {
    can = false;
  }
  // a2 - a3
  if(grid[2][1] - grid[3][1] != grid[2][2] - grid[3][2] ||
    grid[2][2] - grid[3][2] != grid[2][3] - grid[3][3]) {
    can = false;
  }

  // b1 - b2
  if(grid[1][1] - grid[1][2] != grid[2][1] - grid[2][2] ||
    grid[2][1] - grid[2][2] != grid[3][1] - grid[3][2]) {
    can = false;
  }
  // b2 - b3
  if(grid[1][2] - grid[1][3] != grid[2][2] - grid[2][3] ||
    grid[2][2] - grid[2][3] != grid[3][2] - grid[3][3]) {
    can = false;
  }


  if(can) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}