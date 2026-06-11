#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    char s[50][50];
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> s[i][j];
        }
    }
    bool flg = true;
    int cnt =0;
    const int dx[4] = {0, 1, 0, -1}; // 上　右　下　左
    const int dy[4] = {1, 0, -1, 0};
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(s[i][j] == '.') continue;
            cnt = 0;
            for(int k=0; k<4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni < 0 || h <= ni) continue;
                if (nj < 0 || w <= nj) continue;
                if(s[ni][nj] == '#') cnt++;
            }
            if(cnt == 0){
                flg = false; break;
            }
        }
    }
    if(flg) cout << "Yes" << endl;
    else    cout << "No"  << endl;
    return 0;
}