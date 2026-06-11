#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;

int dtate[4]={-1,0,1,0};
int dyoko[4]={0,-1,0,1};

int bfs(const vvc &maze, vvi &arrive, vvi &pre, int sc, int sr, int H, int W){
    pair<int,int> a=make_pair(sr,sc);
    queue<pair<int,int>> que;
    que.push(a);
    arrive[sc][sr]=0;
    while(!que.empty()){
        pair<int,int> v=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int nextr=v.first+dyoko[i];
            int nextc=v.second+dtate[i];
            if(maze[nextr][nextc]=='#') continue;
            if(arrive[nextr][nextc]!=-1) continue;
            arrive[nextr][nextc]=1+arrive[v.first][v.second];
            pre[nextr][nextc]=(i+2)%4;
            //cout << nextr-v.first <<" " << nextc-v.second << endl;
            if(nextr==H&&nextc==W) return 1;
            pair<int,int> temp=make_pair(nextr,nextc);
            que.push(temp);
        }
    }
    return -1;
}

void rootcheck(int H, int W, vvi &pre, vvc &maze){
    maze[H][W]='#';
    int nowr=H,nowc=W;
    while(1){
        int dir=pre[nowr][nowc];
        nowr+=dyoko[dir];
        nowc+=dtate[dir];
        //cout << nowr << " now " << nowc << endl;
        maze[nowr][nowc]='#';
        if(nowr==1&&nowc==1) break;        
    }
    return;
}

int main(){
    int H,W;
    cin >> H >> W;
    vvc maze(H+2,vc(W+2,'#'));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> maze[i][j];
        }
    }
    vvi arrive(H+2,vi(W+2,-1));
    vvi pre(H+2,vi(W+2,-1));

    if(bfs(maze,arrive,pre,1,1,H,W)==-1){
        cout << -1 << endl;
        return 0;
    }
/*
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cout << pre[i][j] << " " ;
        }
        cout << endl;
    }
*/
    rootcheck(H,W,pre,maze);
/*
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cout << maze[i][j] << " " ;
        }
        cout << endl;
    }
*/



    int ans=0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(maze[i][j]=='.') ans++;
        }
    }
    cout << ans << endl;   
    
    
}