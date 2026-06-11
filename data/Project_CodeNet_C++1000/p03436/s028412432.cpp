#include <bits/stdc++.h>
using namespace std;
void tansaku(int X,int Y,vector<vector<int>> masu, vector<vector<int>> &data, queue<tuple<int, int>> &Q,int H,int W){
    Q.pop();
    if(data[X][Y] != -1 || masu[X][Y] == 1){
        return;
    }
    int p = 1000000;
    if (X - 1 >= 0 && data [X - 1][Y] != -1){
        p = min(p,data[X - 1][Y]);
    }
    if (Y - 1 >= 0 && data[X][Y - 1] != -1){
        p = min(p,data[X][Y - 1]);
    }
    if (X + 1 < H && data[X + 1][Y] != -1){
        p = min(p,data[X + 1][Y]);
    }
    if (Y + 1 < W && data[X][Y + 1] != -1){
        p = min(p,data[X][Y + 1]);
    }
    if(p == 1000000){
        data[X][Y] = 0;
    }
    else{
        p++;
        data[X][Y] = p;
    }
    if (X > 0){
        Q.push(make_tuple(X - 1,Y));
    }
    if (Y > 0){
        Q.push(make_tuple(X,Y - 1));
    }
    if (X + 1 < H){
        Q.push(make_tuple(X + 1, Y));
    }
    if (Y + 1 < W){
        Q.push(make_tuple(X, Y + 1));
    }
    return;
}
int main(){
    int H,W,i,j,A,p = 0;;
    char C;
    cin >> H >> W;
    vector<vector<int>> masu(H, vector<int>(W)),data(H, vector<int>(W,-1));
    for(i = 0;i < H;i++){
        for(j = 0;j < W;j++){
            cin >> C;
            if(C == '.'){
                masu[i][j] = 0;
            }
            else{
                masu[i][j] = 1;
                p++;
            }
        }
    }
    queue<tuple<int,int>> Q;
    Q.push(make_tuple(0,0));
    while(!(Q.empty())){
        tansaku(get<0>(Q.front()),get<1>(Q.front()),masu,data,Q,H,W);
    }
    if(data[H - 1][W - 1] == -1){
        cout << -1 << endl;
    }
    else{
        cout << H * W - p - data[H - 1][W - 1] - 1 << endl;
    }
}