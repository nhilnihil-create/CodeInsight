#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> grid(3, vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> grid[i][j];
        }
    }
    if(grid[1][0] - grid[0][0] == grid[1][1] - grid[0][1] &&
       grid[1][1] - grid[0][1] == grid[1][2] - grid[0][2] &&
       grid[2][0] - grid[0][0] == grid[2][1] - grid[0][1] &&
 	   grid[2][1] - grid[0][1] == grid[2][2] - grid[0][2]){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
	return 0;
}

