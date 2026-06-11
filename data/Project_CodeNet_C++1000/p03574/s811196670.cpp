#include<bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    string S;
    cin >> H >> W;
    int dh[] = {1,-1, 0, 0, 1, 1,-1,-1};
    int dw[] = {0, 0,-1, 1, 1,-1, 1,-1};
    vector<vector<char>> X(H+1, vector<char>(W+1, '#')), ans(H+1, vector<char>(W+1, '#'));
    for(int i = 1; i <= H; ++i){
        cin >> S;
        for(int j = 0; j < S.size(); ++j) X[i][j+1] = S[j];
    }
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            if(X[i][j] == '.'){
                int buf = 0;
                for(int k = 0; k < 8; ++k){
                    if(1 <= i+dh[k] && i+dh[k] <= H && 1 <= j+dw[k] && j+dw[k] <= W && X[i+dh[k]][j+dw[k]] == '#') ++buf;
                }
                ans[i][j] = '0'+buf;
            }
        }
    }
    for(int i = 1; i <= H; ++i){
        for(int j = 1; j <= W; ++j){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}