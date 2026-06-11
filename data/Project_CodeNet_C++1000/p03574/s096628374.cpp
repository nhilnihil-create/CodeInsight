#include <bits/stdc++.h>

using namespace std;

int NumMine(vector<string> &data,int i,int j){
    int num = 0;
    if (i>0){
        if(j>0){
            if(data[i-1].at(j-1)=='#'){
                num++;
            }
        }
        if(data[i-1].at(j)=='#'){
            num++;
        }
        if(j<(data[i-1].length()-1)){
            if(data[i-1].at(j+1)=='#'){
                num++;
            }
        }
    }
    if(j>0){
        if(data[i].at(j-1)=='#'){
            num++;
        }
    }
    if(j<(data[i].length()-1)){
        if(data[i].at(j+1)=='#'){
            num++;
        }
    }

    if (i<(data.size()-1)){
        if(j>0){
            if(data[i+1].at(j-1)=='#'){
                num++;
            }
        }
        if(data[i+1].at(j)=='#'){
            num++;
        }
        if(j<(data[i+1].length()-1)){
            if(data[i+1].at(j+1)=='#'){
                num++;
            }
        }
    }
    return num;
}

int main(){
    int H, W;
    cin >> H >> W;

    vector<string> data(H);

    for (int i = 0; i < H;i++){
        cin >> data[i];
    }

    for (int i = 0; i < H;i++){
        for (int j = 0; j < W;j++){
            if(data[i].at(j)!='.'){
                continue;
            }else{
                data[i][j] = '0'+NumMine(data, i, j);
            }
        }
    }

    for (int i = 0; i < H;i++){
        cout << data[i] << endl;
    }
}
