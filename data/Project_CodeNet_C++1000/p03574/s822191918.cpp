#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int H,W;
    cin >> H >> W;
    char S[H][W];
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> S[i][j];
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == '#'){
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        if(0 <= k && k < H && 0 <= l && l < W && S[k][l] != '#') {
                            if(S[k][l] == '.') S[k][l] = '1';
                            else S[k][l] = char(S[k][l] + 1);
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == '.') S[i][j] = '0';
            if(j != W-1) cout << S[i][j];
            else cout << S[i][j] << endl;
        }
    }
    
}