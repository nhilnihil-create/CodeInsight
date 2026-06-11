#include <bits/stdc++.h>
using namespace std;
int main() {
  int h,w; cin>>h>>w;
  char s[w+2][h+2]={' '};
  for(int y=1; y<h+1; y++){
    for(int x=1; x<w+1; x++){
      cin>>s[x][y];
    }
  }
  for(int y=1; y<h+1; y++){
    for(int x=1; x<w+1; x++){
      if(s[x][y]=='#') {
        cout<<'#'; continue;
      }
      int cnt=0;
      if(s[x-1][y-1]=='#') cnt++;
      if(s[x][y-1]=='#') cnt++;
      if(s[x+1][y-1]=='#') cnt++;
      if(s[x-1][y]=='#') cnt++;
      if(s[x+1][y]=='#') cnt++;
      if(s[x-1][y+1]=='#') cnt++;
      if(s[x][y+1]=='#') cnt++;
      if(s[x+1][y+1]=='#') cnt++;
      cout<<cnt;
    }
    cout<<endl;
  }
}
