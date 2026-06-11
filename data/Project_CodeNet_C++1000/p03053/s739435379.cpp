#include <iostream> 
#include <queue>
#include <cstring>
char board[1005][1005];
#define pii pair<int, int>
using namespace std;

int ShortestPath[1005][1005];
int R, C;
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

bool inside(int r, int c){
    return 0<=r && r<R && 0<=c &&c<C;
}

int bfs(){
    queue<pii> a;
    memset(ShortestPath, -1, sizeof(ShortestPath));
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(board[i][j]=='#'){
                ShortestPath[i][j]=0;
                a.push(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    while(!a.empty()){
        pii now = a.front(); a.pop();
        int row = now.first;
        int col = now.second;
        
        ans = max(ans, ShortestPath[row][col]);

        for(int x=0; x<4; x++){
            int vr = row+dx[x];
            int vc = col+dy[x];
            if(!inside(vr, vc))continue;
            if(ShortestPath[vr][vc]!=-1)continue;
            ShortestPath[vr][vc] = ShortestPath[row][col] + 1;
            a.push(make_pair(vr, vc));
        }
    }
    return ans;
}

int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
        }
    }
    cout << bfs() << endl;
}