#include <bits/stdc++.h>
using namespace std;

int main(){
int H,W;

cin>>H>>W;
char S[H][W];
for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
cin>>S[i][j];
  }
}
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
int ans=0;
if(S[i][j]=='#'){
continue;
}
for(int k=0;k<8;k++){
int ni=i+dx[k];
int nj=j+dy[k];
  if(H<=ni||W<=nj||ni<0||nj<0){
  continue;
  }
if(S[ni][nj]=='#'){
ans++;
}

}
S[i][j]=char('0'+ans);
}
}
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){  
cout<<S[i][j];    

}
cout<<endl;
}
}
  

