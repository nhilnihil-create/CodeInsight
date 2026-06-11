#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int numRows;
    cin >> numRows;
    int numCols;
    cin >> numCols;
    vector<string> grid;
    for(int i = 0; i < numRows; i++) {
        string row;
        cin >> row;
        grid.push_back(row);
    }

    unsigned long long mod = 1e9 + 7;

    vector<unsigned long long> numPathsTop(numCols, 0);
    int numPathsLeft = 1;

    for(int row = 0; row < numRows; row++) {
        for(int col = 0; col < numCols; col++) {
            if(grid[row][col] == '#') {
                numPathsTop[col] = 0;
            } else {
                numPathsTop[col] = (numPathsLeft + numPathsTop[col]) % mod;
            }
            numPathsLeft = numPathsTop[col];
        }
        numPathsLeft = 0;
    }

    cout << numPathsTop[numCols-1];
    
    return 0;
}