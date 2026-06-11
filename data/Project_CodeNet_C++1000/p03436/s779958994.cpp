#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

void output(vector<int> s){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<s[i];
    }
    cout<<endl;
}

int accumulate(int* a,int n){
    return accumulate(a,a+n,0LL);
}

int accumulate(vector<int> a){
    return accumulate(a.begin(),a.end(),0LL);
}

//幅優先探索。このままだと連結してないとダメ。
//disは各座標への距離。行けない場合は-1にしている。
//chaは各座標の情報。文字で格納している。
//sはスタートの座標
//gはゴールの座標
int bfs(vector<vector<int>> dis,vector<vector<char>>cha,pair<int,int>s,pair<int,int>g){
    int h=dis.size();
    int w=dis.at(0).size();

    queue<pair<int,int>> Q;
    Q.push(s);
    dis.at(s.first).at(s.second)=0;

    while(dis.at(g.first).at(g.second)==-1 && Q.size()!=0){
        int y,x;//今の座標
        y=Q.front().first; x=Q.front().second;
        Q.pop();

        int dy[4]={1,0,-1,0};
        int dx[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int ey=y+dy[i];
            int ex=x+dx[i];
            if(ex<0||ey<0||ex>=w||ey>=h) continue;
            if(cha[ey][ex]=='#'||dis[ey][ex]!=-1) continue;
            dis[ey][ex]=dis[y][x]+1;
            Q.push(make_pair(ey,ex));
        }
    }

    return dis.at(g.first).at(g.second);
}

int count_white(vector<vector<char>> grid){
    int h=grid.size(); int w=grid[0].size();
    int ans=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(grid[i][j]=='.') ans++;
        }
    }
    return ans;
}

signed main(){ 
   int h,w; cin>>h>>w;
   vector<vector<char>> grid(h,vector<char>(w));
   vector<vector<int>> dis(h,vector<int>(w,-1));

   for(int i=0;i<h;i++){
       for(int j=0;j<w;j++){
           cin>>grid[i][j];
       }
   }

   int white=count_white(grid);

   int distance=bfs(dis,grid,make_pair(0,0),make_pair(h-1,w-1));
   //cout<<white<<endl;
   //cout<<distance<<endl;
   if(distance==-1){
       cout<<-1<<endl;
   }else{
       cout<<white-(distance+1)<<endl;
   }
}  