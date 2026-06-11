#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<string>> board(H, vector<string>(W));

    for(int i = 0 ; i < H ; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size() ; j++){
            board.at(i).at(j) = s.at(j);
        }

    }

    vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
    vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

    for(int i = 0 ; i < H ; i++){
        for(int j = 0; j < W ; j++){
            if(board.at(i).at(j) == "#"){
                continue;
            }

            int num = 0;
            for(int d = 0; d < 8 ; d++){
                const int ni = i + dx[d];
                const int nj = j + dy[d];

                if(ni < 0 || H <= ni){
                    continue;
                }
                if(nj < 0 || W <= nj){
                    continue;
                }
                if(board.at(ni).at(nj) == "#"){
                    num++;
                    
                }
            }

            board.at(i).at(j) = char(num + '0');
        }

    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << board.at(i).at(j);
        }
        cout << endl;
    }

}