#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int H,W;

/*
bool check(vector<vector<char>> &field, int x, int y){
    
    
}
*/

int main(){
    
    cin >> H >> W;
    H=H+2;
    W=W+2;
    //cout << H;
    //データを受け取る
    vector<vector<char>> field(H,vector<char>(W));
    
    rep(i,H){
        rep(j,W){
            if(i==0 || j==0 || i==H-1 || j==W-1){
                field[i][j]='.';
            }else{
                cin >> field[i][j];
            }
        }
    }
    
    bool ans_flg=true;
    rep(i,H){
        rep(j,W){
            if(field[i][j]=='#'){
                if(field[i-1][j]=='.' && field[i+1][j]=='.' && field[i][j-1]=='.' && field[i][j+1]=='.'){
                    ans_flg=false;
                }
            }
            //cout << field[i][j];
        }
        //cout << endl;
    }
    
    if(ans_flg){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
