#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
struct Point{
    int x;
    int y;
    vector<Point> next;
    void get_next(vector<vector<int>> map){
        int py=y+1;int px=x;
        if(map[py][px]!=inf){
            Point buf;
            buf.x=px;buf.y=py;
            next.push_back(buf);
        }
        py=y-1;px=x;
        if(map[py][px]!=inf){
            Point buf;
            buf.x=px;buf.y=py;
            next.push_back(buf);
        }
        py=y;px=x+1;
        if(map[py][px]!=inf){
            Point buf;
            buf.x=px;buf.y=py;
            next.push_back(buf);
        }
        py=y;px=x-1;
        if(map[py][px]!=inf){
            Point buf;
            buf.x=px;buf.y=py;
            next.push_back(buf);
        }
    }
};
struct Map{
int h;
int w;
char road='.';//道を表す文字
char wall='#';//壁を表す文字
vector<vector<int>> map;
void mkmap(int in_h,int in_w,vector<string> const& input){
    h=in_h;w=in_w;
    for(int i=0;i<=h+1;i++){
        map.push_back(vector<int>(w+2,inf));
    }
    //道ならinf-1にする処理
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(input[i][j]==road){
                map[i+1][j+1]--;
            }
            //map[i+1][j+1]=input[i][j];
        }
    }
}
void output(){
    for(int i=0;i<=h+1;i++){
        for(int j=0;j<=w+1;j++){
            if(this->map[i][j]==inf)cout<<wall;
            else cout<<map[i][j];
        }
        cout<<endl;
    }
}
void BFS(int sx,int sy){
Point s;s.x=sx;s.y=sy;
queue<Point> que;
vector<vector<int>> memo(h+2,vector<int> (w+2,inf));
que.push(s);
this->map[s.y][s.x]=0;
memo[s.y][s.x]=0;
while(!que.empty()){
    Point buf;
    buf=que.front();
    que.pop();
    buf.get_next(map);
    int num=buf.next.size();
    for(int i=0;i<num;i++){
        if(memo[buf.next[i].y][buf.next[i].x]>memo[buf.y][buf.x]+1){
            que.push(buf.next[i]);
            memo[buf.next[i].y][buf.next[i].x]=memo[buf.y][buf.x]+1;
        }
    }
}
for(int i=0;i<=h+1;i++){
  for(int j=0;j<=w+1;j++){
    map[i][j]=memo[i][j];
  }
}
}
int map_max(){
    int max=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(map[i][j]!=inf){
                if(map[i][j]>max)max=map[i][j];
            }
        }
    }
    return max;
}
int dist(int y,int x){
    return map[y][x];
}
};

signed main(){
  int h,w;cin>>h>>w;
  vector<string> s(h);
  rep(i,h)cin>>s[i];
  Map lab;
  lab.mkmap(h,w,s);
  lab.BFS(1,1);
  int res=0;
  rep(i,h){
      rep(j,w){
          if(s[i][j]=='.')++res;
      }
  }
  res-=1;
  res-=lab.dist(h,w);
  if(res<0)res=-1;
  cout<<res<<"\n";
  return 0;
}