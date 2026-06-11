#include<iostream>
#include<queue>
using namespace std;

int H,W;
char s[100][100];

int dist[100][100];
bool visited[100][100];
int white_cnt=0;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int ans=-1;

class Node{
public:
    int x,y;
    Node(int a, int b):x(a),y(b){}
};

void input(){
    cin>>H>>W;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            cin>>s[i][j];
            if(s[i][j]=='.') ++white_cnt;
        }
    }
}

void init(){
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            dist[i][j]=-1;
        }
    }
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            visited[i][j]=false;
        }
    }
}

void bfs(){
    init();
    queue<Node> que;
    Node S(0,0);
    visited[0][0]=true;
    dist[0][0]=0;
    que.push(S);
    while(!que.empty()){
        Node cur=que.front();
        que.pop();
        int cur_x=cur.x;
        int cur_y=cur.y;
        for(int i=0;i<4;++i){
            int next_x=cur_x+dx[i];
            int next_y=cur_y+dy[i];
            bool b=0<=next_x&&next_x<W&&0<=next_y&&next_y<H;
            if(s[next_y][next_x]=='#'||visited[next_y][next_x]||!b) continue;
            visited[next_y][next_x]=true;
            dist[next_y][next_x]=dist[cur_y][cur_x]+1;
            Node next(next_x,next_y);
            que.push(next);
        }
    }   
}

void output(){
    if(dist[H-1][W-1]==-1) cout<<-1<<endl;
    else cout<<white_cnt-dist[H-1][W-1]-1<<endl;
}

int main(){
    input();
    bfs();
    output();
}