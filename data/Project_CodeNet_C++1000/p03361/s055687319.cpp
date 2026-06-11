#include<bits/stdc++.h>
using namespace std;

bool judge(int y, int x, int H, int W, vector<vector<char>> &grid){
    if(y-1>=0){
        if(grid.at(y-1).at(x) == '#')return true;
    }
    if(y+1<=H-1){
        if(grid.at(y+1).at(x) == '#')return true;
    }
    if(x-1>=0){
        if(grid.at(y).at(x-1) == '#')return true;
    }
    if(x+1<=W-1){
        if(grid.at(y).at(x+1) == '#')return true;
    }
    return false;
}

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> grid(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> grid.at(i).at(j);
        }
    }

    vector<vector<char>> canvas(H,vector<char>(W));
    bool achive = true;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(grid.at(i).at(j) == '#'){
                if(!judge(i,j,H,W,grid))achive = false;
            }
        }
    }
    if(achive){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}