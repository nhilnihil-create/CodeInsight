#include <bits/stdc++.h>

using namespace std;

int main(){

    int H, W, h, w, counter = 0;

    cin >> H >> W >> h >> w;

    int arr[H][W] = {0};

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            arr[i][j] = 0;
            //cout << arr[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << "-------" << endl;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < W; j++){
            arr[i][j] = 1;
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < w; j++){
            arr[i][j] = 1;
        }
    }



    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(arr[i][j] == 0){
                counter++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}
