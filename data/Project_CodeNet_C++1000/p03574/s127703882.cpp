#include <bits/stdc++.h>
using namespace std;

int main (void){
    int H,W;
    cin >> H >> W;
    string S[H+10];
    for(int i=0;i<H;i++){
        cin >> S[i] ;
    }
    const int dx[8] = {1,0,-1,0,1,-1,-1,1};
    const int dy[8] = {0,1,0,-1,1,1,-1,-1};
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == '.'){
                int count=0;
                for(int k=0;k<8;k++){
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if(ni<0 || ni >= H) continue;
                    if(nj<0 || nj >= W) continue;
                    if(S[ni][nj] == '#') count++;
                }
                //int -> charへのキャスト　charの末尾に'0'をつける
                //https://marycore.jp/prog/c-lang/convert-number-to-char/
                S[i][j] = char(count + '0');
            }
        }
    }
    for(int i=0 ;i<H;i++){
        cout << S[i] << endl;
    }
    return 0;
}