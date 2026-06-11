#include <iostream>
#include <bitset>
using namespace std;

int main() {
    
    int H, W;
    cin >> H >> W;

    char table[H][W];

    for (int i = 0; i < H; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); j++) {
            table[i][j] = line.at(j);
        }

    }

    for (int i = 0; i < H; i++) {

        for (int j = 0; j < W; j++) {

            int cnt = 0;
            if (table[i][j] == '.'){
                //cout << "HIT" << endl;;

                 // 爆弾カウントここから
                
                for (int hi = -1; hi <= 1; hi++) {
                    for (int wj = -1; wj <= 1; wj++) {

                        int target_i = i + hi;
                        int target_j = j + wj;

                        if (target_i < 0 || target_i >= H){
                            continue;
                        }
                        if (target_j < 0 || target_j >= W){
                            continue;
                        }

                        if (table[target_i][target_j] == '#' ){
                            cnt++;
                        }
                    }
                }

                //  爆弾カウントここまで
                table[i][j] = char(cnt + '0');

            }
        }
    }

    for (int i = 0; i < H; i++) {

        for (int j = 0; j < W; j++) {

            cout << table[i][j];
        }
        cout << endl;

    }
}


