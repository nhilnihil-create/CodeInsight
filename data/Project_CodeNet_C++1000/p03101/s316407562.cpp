#include <iostream>
#include <vector>
using namespace std;
int main(void){
    
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> Cells(H, vector<bool>(W, true));
    
    int h, w;
    cin >> h >> w;
    
    for(int i = 0; i < W; i++){
        Cells[h-1][i] = false;
    }

    for(int i = 0; i < H; i++){
        Cells[i][w-1] = false;
    }
    
    int ans = 0;
    for(int i = h; i < H; i++){
        for(int j = w; j < W; j++){
            if(Cells[i][j] == true) ans++;
        }cout << endl;
    }
    
    
    cout << ans << endl;
}
