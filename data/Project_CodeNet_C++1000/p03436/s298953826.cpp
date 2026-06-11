#include <iostream>
#include <queue>
using namespace std;

int H,W;
char s[57][57];
int d[57][57];

int vx[4] = {0,1,0,-1};
int vy[4] = {1,0,-1,0};

int wall = 0;

void write(){
    string row[100];
    for(int y = 1;y < H+1;y++){
        for(int x = 1;x < W+1;x++){
            row[y] += s[x][y];
        }
    }

    cout << "" << endl;
    for(int y = 1;y < H+1;y++){
        cout << row[y] << endl;
    }

}

int bfs(){
    int way = 8192;
    pair<int,int> p;
    queue < pair<int,int> > Q;
    Q.push(make_pair(1,1) );
    d[1][1] = 0;
    s[1][1] = '#';

    while(!Q.empty()){
        //write();
        p = Q.front(); Q.pop();

        if(p.first == W && p.second == H){
            way = d[p.first][p.second];
            break;
        }
        

        for(int i = 0;i < 4;i++){
            int nx = p.first + vx[i];
            int ny = p.second + vy[i];

            if(1 <= nx && nx <= W && 1 <= ny && ny <= H && s[nx][ny] == '.'){
                Q.push(make_pair(nx,ny)); 
                s[nx][ny] = '#';
                d[nx][ny] = d[p.first][p.second] + 1;

                if(nx == W && ny == H){
                    way = d[nx][ny];
                    break;
                }
            }

        }
    }

    return way;
}

int main(){
    cin >> H >> W;
    for(int y = 1;y < H + 1;y++){
        for(int x = 1;x < W + 1;x++){
            cin >> s[x][y];
            if(s[x][y] == '#') wall++;
        }
    }
    int way = bfs(); 

    int ans = W * H - (way + 1 + wall);

    if(way == 8192){
        ans = -1;
    }

    //cout << "最短手順:" << way << " 壁:" << wall << endl;
    cout << ans << endl;
}