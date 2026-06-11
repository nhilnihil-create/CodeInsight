#include<bits//stdc++.h>
using namespace std;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(25);
    
    int H,W;
    cin >> H >> W;
    char temp;
    int c[H][W];
    int flag[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> temp;
            if(temp == '.'){
                c[i][j] = 0;
            }
            if(temp == '#'){
                c[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            flag[i][j] = 1e9 + 10;
        }
    }


    int ans = 0;
    queue<int> x,y;
    //多点スタート
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(c[i][j] == -1){
                flag[i][j] = 0;
                x.push(j);
                y.push(i);
            }
        }
    }

    while(!y.empty()){
        int nx = x.front();
        int ny = y.front();
        x.pop();
        y.pop(); 
        for(int i = 0; i < 4; i++){
            int ry = ny + dy[i], rx = nx + dx[i];
            if(ry < 0 || ry >= H || rx < 0 || rx >= W) continue;
            if (flag[ry][rx] > flag[ny][nx] + 1){
                flag[ry][rx] = flag[ny][nx] + 1;
                x.push(rx);
                y.push(ry);
            }
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(flag[i][j] >= ans){
                ans = flag[i][j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}