#include <bits/stdc++.h>
using namespace std;
//Darker and Darker

typedef pair<int, int> Position;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char> > A(H, vector<char>(W));
    vector<vector<int> > reach(H, vector<int>(W));
    queue<Position> q;

    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){    
            cin >> A[i][j];
            if(A[i][j] == '#'){
                q.push(make_pair(i,j));                
                reach[i][j] = 0;
            }else{
                reach[i][j] = -1;
            }
        }
    }

    while(!q.empty()){
        Position p = q.front();
        q.pop();
        int x = p.first; int y = p.second;
        
        if(x + 1 < H && A[x + 1][y] != '#' && reach[x + 1][y] == -1){
            reach[x + 1][y] = reach[x][y] + 1;
            q.push(make_pair(x + 1, y));
        }   
        if(0 <= x - 1 && A[x - 1][y] != '#' && reach[x - 1][y] == -1){
            reach[x - 1][y] = reach[x][y] + 1;
            q.push(make_pair(x - 1, y));
        }
        if(y + 1 < W && A[x][y + 1] != '#' && reach[x][y + 1] == -1){
            reach[x][y + 1] = reach[x][y] + 1;
            q.push(make_pair(x, y + 1));
        }
        if(0 <= y - 1 && A[x][y - 1] != '#' && reach[x][y - 1] == -1){
            reach[x][y - 1] = reach[x][y] + 1;
            q.push(make_pair(x, y - 1));
        }
    }

    int ans = 0;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            ans = max(ans, reach[i][j]);
            // cout << reach[i][j];
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}