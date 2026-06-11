#include <bits/stdc++.h>
using namespace std;

int H, W;
char s[50][50];

int check(int x, int y){
  bool k=false;
  if(x>0 && s[x-1][y]==1){
    k=true;
    s[x-1][y]=0;
    check(x-1, y);
  }
  if(y<W && s[x][y+1]==1){
    k=true;
    s[x][y+1]=0;
    check(x, y+1);
  }
  if(x<H && s[x+1][y]==1){
    k=true;
    s[x+1][y]=0;
    check(x+1, y);
  }
  if(y>0 && s[x][y-1]==1){
    k=true;
    s[x][y-1]=0;
    check(x, y-1);
  }
  s[x][y]=-1;
  return k;
}

int main() {
  cin >> H >> W;
  
  for(int i=0 ; i<H ; i++){
    string str;
    cin >> str;
    for(int j=0 ; j<W ; j++){
      if(str[j]=='.')
        s[i][j]=-1;
      else
        s[i][j]=1;
    }
  }
  
  for(int i=0 ; i<H ;i++)
    for(int j=0 ; j<W ; j++)  
      if(s[i][j]==1)
        if(!check(i, j)){
          cout << "No" << endl;
          return 0;
        }
  cout << "Yes" << endl;
}