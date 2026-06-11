#include <bits/stdc++.h>
using namespace std;
int main() {
  int h,w; cin>>h>>w;
  char s[h+2][w+2];
  int dx[4]={1,0,-1,0};
  int dy[4]={0,-1,0,1};
  for(int x=0;x<w+2;x++) s[0][x]='.',s[h+1][0]='.';
  for(int y=0;y<h+2;y++) s[y][0]='.',s[y][w+1]='.';
  for(int y=1;y<h+1;y++) for(int x=1;x<w+1;x++) cin>>s[y][x];
  for(int y=1;y<h+1;y++) for(int x=1;x<w+1;x++){
    if(s[y][x]=='#'){
      bool f=false;
      for(int i=0;i<4;i++) if(s[y+dy[i]][x+dx[i]]=='#') f=true;
      if(!f){cout<<"No"; return 0;}
    }
  }
  cout<<"Yes";
}