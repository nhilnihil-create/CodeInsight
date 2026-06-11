#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
signed main(){
  int H,W;
  cin>>H>>W;
  vector<string> A(H);
  for(string &S:A)cin>>S;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      if(A[i][j]=='.')goto home;
      for(int k=0;k<4;k++){
        int x=i+dx[k],y=j+dy[k];
        if(0<=x && x<H && 0<=y && y<=W && A[x][y]=='#')goto home;
      }
      puts("No");
      return 0;
      home:;
    }
  puts("Yes");
}