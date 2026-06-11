#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  string bo[h];
  const int dx[8]={1,0,-1,0,1,-1,-1,1};
  const int dy[8]={0,1,0,-1,1,1,-1,-1};
  for (int i=0;i<h;i++) cin>>bo[i];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(bo[i][j]=='#') continue;
      int sum=0;
      for(int k=0;k<8;k++){
        const int ni=i+dx[k];
        const int nj=j+dy[k];
        if(ni<0||ni>=h) continue;
        if(nj<0||nj>=w) continue;
        if(bo[ni][nj]=='#') sum++;
      }
      bo[i][j]=char(sum+'0');
    }
  }
  for (int i=0;i<h;i++) cout<<bo[i]<<endl;
}