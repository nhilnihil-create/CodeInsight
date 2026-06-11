#include<iostream>
#include<queue>
using namespace std;
using P=pair<int,int>;
const int value=1000000;
const int x[4]={1,0,-1,0},y[4]={0,1,0,-1};
int h,w;
int x1,y1,x2,y2;
char s[50][50];
int a[50][50];
int BFS(void){
  queue<P> que;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      a[i][j]=value;
    }
  }
  a[x1][y1]=0;
  que.push(P(x1,y1));
  while(que.size()){
    P p=que.front();
    que.pop();
    for(int i=0;i<4;i++){
      int x3=p.first+x[i],y3=p.second+y[i];
      if(0<=x3 && x3<h && 0<=y3 && y3<w && s[x3][y3]=='.' && a[x3][y3]==value){
        a[x3][y3]=a[p.first][p.second]+1;
        if(x2==x3 && y2==y3){
          return a[x3][y3]+1;
        }
        que.push(P(x3,y3));
      }
    }
  }
  return a[x2][y2]+1;
}
int main(void){
  cin>>h>>w;
  x1=0,y1=0;
  x2=h-1,y2=w-1;
  int mul=h*w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='#'){
        --mul;
      }
    }
  }
  mul-=BFS();
  if(a[x2][y2]==value){
    mul=-1;
  }
  cout<<mul<<endl;
  return 0;
}