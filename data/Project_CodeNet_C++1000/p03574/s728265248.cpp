#include<bits/stdc++.h>
using namespace std;

int countBomb(vector<vector<char>> &v, int H, int W);
char itoc(int i);

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>>v(H,vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> v.at(i).at(j);
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(v.at(i).at(j)!='#')v.at(i).at(j)=itoc(countBomb(v,i+1,j+1));
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << v.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}

int countBomb(vector<vector<char>> &v, int H, int W){
    int count = 0;
    for(int i = -1; i <= 1; i++){
        if((H-1)+i<0||(H-1)+i>=v.size())continue;
        for(int j = -1; j <= 1; j++){
            if((W-1)+j<0||(W-1)+j>=v.at((H-1)+i).size())continue;
            if(v.at((H-1)+i).at((W-1)+j)=='#')count++;
        }
    }
    return count;
}

char itoc(int i){
    return to_string(i).at(0);
}