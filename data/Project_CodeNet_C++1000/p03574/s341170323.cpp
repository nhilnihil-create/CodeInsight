#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    string s[H];
    for(int i = 0; i < H; i++){
        cin >> s[i];
    }
    int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i].at(j) == '#'){
                continue;
            }
            int num = 0;
            for(int k = 0; k < 8; k++){
                int ni = i + dy[k];
                int nj = j + dx[k];
                if(ni < 0 || H <= ni){
                    continue;
                }
                if(nj < 0 || W <= nj){
                    continue;
                }
                if(s[ni].at(nj) == '#'){
                    num++;
                }
            }
            s[i].at(j) = char(num + '0');
        }
        cout << s[i] << endl;
    }
}