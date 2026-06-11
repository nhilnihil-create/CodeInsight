#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));
    vector<vector<int>> num(H, vector<int>(W, -1));
    int cnt = 0;
    rep(i, H) rep(j, W){
        cin >> s[i][j];
        if(s[i][j] == '.'){
            cnt++;
        }
    }
    queue<int> xq, yq;
    yq.push(0); xq.push(0);
    num[0][0] = 1;
    int ans = -1;
    while(yq.size()){
        int y = yq.front(), x = xq.front();
        vector<int> yv = {0,1,0,-1}, xv = {1,0,-1,0};
        rep(i, 4){
            int yt = y + yv[i], xt = x + xv[i];
            if(yt < 0 || yt >= H || xt < 0 || xt >= W) continue;
            if(num[yt][xt] == -1 && s[yt][xt] == '.'){
                yq.push(yt); xq.push(xt);
                num[yt][xt] = num[y][x] + 1;
            }
        }
        yq.pop(); xq.pop();
        if(num[H-1][W-1] != -1){
            ans = cnt - num[H-1][W-1];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}