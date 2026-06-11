#include <bits/stdc++.h>
using namespace std;
int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for(int i = 0; i < H; i++) cin >> S[i];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.'){
                int cnt = 0;
            for(int k = 0; k < 8; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '#'){
                    cnt++;
                }
            }
            S[i][j] = '0' + cnt;
            }
        }
    }
    for(int i = 0; i < H; i++) cout << S[i] << endl;
}