#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

const int nmax = 1000;
char table[nmax][nmax];

int bfs(int H,int W){
    queue<P> q;
    P pos;
    int n_x,n_y,x,y,count1,count2,ans;
    int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    count1 = 0;
    count2 = 0;
    ans = 0;
    for(int y = 0;y < H;y++){
        for(int x = 0;x < W;x++){
            if(table[y][x] == '#'){
                q.push(P(x,y));
                count1++;
            }
        }
    }
    while(!q.empty()){
        pos = q.front();
        q.pop();
        count1--;
        n_x = pos.first;
        n_y = pos.second;
        for(int i = 0;i < 4;i++){
            x = n_x + direction[i][0];
            y = n_y + direction[i][1];
            if(x < 0 || W <= x || y < 0 || H <= y) continue;
            if(table[y][x] == '#') continue;
            table[y][x] = '#';
            q.push(P(x,y));
            count2++;
        }
        if(count1 == 0){
            ans++;
            count1 = count2;
            count2 = 0;
        }
    }
    return --ans;
}

int main(){
    int H,W;

    cin >> H >> W;
    for(int y = 0;y < H;y++){
        for(int x = 0;x < W;x++){
            cin >> table[y][x];
        }
    }

    cout << bfs(H,W) << endl;
}