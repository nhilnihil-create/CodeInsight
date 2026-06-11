#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(h + 2, vector<char>(w + 2, '.'));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> board[i][j];
        }
    }
    
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(board[i][j] == '#'){
                if(board[i - 1][j] == '#' || board[i][j - 1] == '#' || board[i + 1][j] == '#' || board[i][j + 1] == '#'){
                    
                }else{
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    
    /*for(int i = 0; i <= h + 1; i++){
        for(int j = 0; j <= w + 1; j++){
            cout << board[i][j];
        }
        cout << endl;
    }*/
    return 0;
}
