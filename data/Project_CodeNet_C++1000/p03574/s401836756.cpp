#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    string board[60];
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < H; i++) {
        cin >> board[i];
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(board[i][j] == '.') {
                int count = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 0 && x < H && y >=0 && y < W && board[x][y] =='#') {
                        count++;
                    }
                }
                board[i][j] = '0' + count;
            }
        }
    }
    for(int i = 0; i < H; i++) {
        cout << board[i] << endl;
    }
}