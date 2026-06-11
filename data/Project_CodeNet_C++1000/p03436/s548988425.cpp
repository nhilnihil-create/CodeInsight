#include <bits/stdc++.h>
using namespace std;
//Grid Repainting

typedef pair<int, int> Position;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<char> > s(H, vector<char>(W));
    vector<vector<int> > reach(H, vector<int>(W));
    int black = 0;

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            char a;
            cin >> a;
            if(a == '#')black++;
            s[i][j] = a;
            reach[i][j] = -1;
        }
    }
    int d = 0;
    queue<Position> q;
    q.push(make_pair(0,0));
    reach[0][0] = 0;
    while(!q.empty()){
        Position p = q.front();
        q.pop();
        int x = p.first; int y = p.second;
        if(x == H - 1 && y == W - 1){
            cout << H*W - black - reach[x][y] - 1 << endl;
            return 0;
        }
        if(x + 1 < H && s[x + 1][y] != '#' && reach[x + 1][y] == -1){
            reach[x + 1][y] = reach[x][y] + 1;
            q.push(make_pair(x + 1, y));           
        } 
        if(0 <= x - 1 && s[x - 1][y] != '#' && reach[x - 1][y] == -1){
            reach[x - 1][y] = reach[x][y] + 1;
            q.push(make_pair(x - 1, y));           
        }
        if(y + 1 < W && s[x][y + 1] != '#' && reach[x][y + 1] == -1){
            reach[x][y + 1] = reach[x][y] + 1;
            q.push(make_pair(x, y + 1));           
        }
        if(0 <= y - 1 < H && s[x][y - 1] != '#' && reach[x][y - 1] == -1){
            reach[x][y - 1] = reach[x][y] + 1;
            q.push(make_pair(x, y - 1));           
        }
    }
    cout << -1 << endl;
    return 0;

}