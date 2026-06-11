#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H){
        cin >> S[i];
    }

    char c;
    for(int j=0; j<H; j++){
        for(int k=0; k<W; k++){
            c = S[j][k];
            if(c == '#'){continue;}

            int val = 0;
            for(int d_j: {-1, 0, 1}){
                for(int d_k: {-1, 0, 1}){
                    if(d_j == 0 && d_k == 0)continue;

                    int x = k + d_k;
                    int y = j + d_j;

                    if( x >= 0 && x < W && y >=0 && y < H ){
                        val += (S[y][x] == '#')? 1 : 0;
                    }
                }
            }
            S[j][k] = val + '0';
        }
    }

    for(int j=0; j<H; j++){
        for(int k=0; k<W-1; k++){
            cout << S[j][k];
        }
        cout << S[j][W-1] << endl;;
    }
}