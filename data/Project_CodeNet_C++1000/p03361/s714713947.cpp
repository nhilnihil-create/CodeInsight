#include <bits/stdc++.h>
using namespace std;

int main(void){
    int H,W;
    cin >> H >> W;
    string S[H+10];
    for(int i=0;i<H;i++){
        cin >> S[i];
    }
    const int dx[4] = {0,1,-1,0};
    const int dy[4] = {1,0,0,-1};
    bool can = true;
    //上下左右に黒いマスがない黒いマスを探索
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int count = 0;
            if(S[i][j] == '.') continue;
            for(int k=0;k<4;k++){
                int ni = i + dy[k];
                int nj = j + dx[k];
                if(S[ni][nj] == '.'){
                    count++;
                }
            }
            if(count == 4){
                can = false;
            }

        }
    }
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}