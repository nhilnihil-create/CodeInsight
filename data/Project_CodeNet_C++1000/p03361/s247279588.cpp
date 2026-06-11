#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    bool flag = false;
    for (int i=0; i<h; i++) for (int j=0; j<w; j++) cin >> grid[i][j];
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (grid[i][j] == '#'){
                if ((i==0 && j==0) && (grid[i][j+1]=='.') && (grid[i+1][j]=='.')) flag = true;
                else if ((i==0 && j==w-1) && (grid[i][j-1]=='.') && (grid[i+1][j]=='.')) flag = true;
                else if ((i==h-1 && j==0) && (grid[i-1][j]=='.') && (grid[i][j+1]=='.')) flag = true;
                else if ((i==h-1 && j==w-1) && (grid[i-1][j]=='.') && (grid[i][j-1]=='.')) flag = true;
                else if ((i == 0) && (grid[i][j-1]=='.') && (grid[i][j+1]=='.') && (grid[i+1][j]=='.')) flag = true;
                else if ((i == h-1) && (grid[i][j-1]=='.') && (grid[i][j+1]=='.') && (grid[i-1][j])=='.') flag = true;
                else if ((j == 0) && (grid[i-1][j]=='.') && (grid[i+1][j]=='.') && (grid[i][j+1]=='.')) flag = true;
                else if ((j == w-1) && (grid[i-1][j]=='.') && (grid[i+1][j]=='.') && (grid[i][j-1]=='.')) flag = true;
                else if (grid[i][j-1]=='.' && grid[i][j+1]=='.' && grid[i-1][j]=='.' && grid[i+1][j]=='.') flag = true;
                if (flag){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}