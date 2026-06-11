#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int H,W;


bool onBoard(int y,int x){
    if(y>=0&&y<H&&x>=0&&x<W){
        return true;
    }
    return false;
}

int main() {
    cin >> H >>W;
    vector<string> A(H);
    for(int i=0;i<H;i++){
        cin >> A[i];
    }
    queue<pair<int,int>> q;
    int d[H][W];
    memset(d,-1,sizeof(d));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A[i][j] == '#'){
                d[i][j] =0;
                q.emplace(i,j);
            }
        }
    }
    int ans =0;
    int dy[] = {1,0,-1,0};
    int dx[] = {0,1,0,-1};
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(onBoard(ny,nx) && d[ny][nx] == -1){
                d[ny][nx] = d[y][x] +1;
                ans = max(ans,d[ny][nx]);
                q.emplace(ny,nx);
            }
        }
    }
    cout << ans << endl;

    return 0;
}