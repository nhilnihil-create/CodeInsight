#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1010, MAXE = 1000010;

int offset[8][2] = {
{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };
const int MAXN = 100;
char grid[MAXN][MAXN];
char maze[MAXN][MAXN];
int rows, columns, total = 0;

int main(int argc, char *argv[])
{
    

    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> rows >> columns;
    
    memset(maze, ' ', sizeof(maze));
    memset(grid, ' ', sizeof(grid));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> maze[i][j];
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (maze[i][j] == '#') {
                grid[i][j] = '#';
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 8; k++){
                int ii = i + offset[k][0], jj = j + offset[k][1];
                
                if (ii < 0 || ii >= rows || jj < 0 || jj >= columns) {
                    continue;
                }
                
                if (maze[ii][jj] == '#') {
                    cnt++;
                }
                
            }
            grid[i][j] = cnt + '0';
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
}
