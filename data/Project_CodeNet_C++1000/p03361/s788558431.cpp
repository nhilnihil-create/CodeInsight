#include <iostream>
using namespace std;

int main(void){
    int h, w;
    cin >> h >> w;
    char grid[h+2][w+2];
    for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) cin >> grid[i][j];
    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
            if (grid[i][j]=='#' && grid[i-1][j]!='#' && grid[i+1][j]!='#' && grid[i][j-1]!='#' && grid[i][j+1]!='#'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}