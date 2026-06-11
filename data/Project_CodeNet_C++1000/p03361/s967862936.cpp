#include <bits/stdc++.h>
using namespace std;

int main(){
int H,W;

cin>>H>>W;
char S[H][W];
int A[H][W];
for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
cin>>S[i][j];
  }
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
if(S[i][j]=='.'){
A[i][j]=1;
continue;
}
for(int k=0;k<4;k++){
int ni=i+dx[k];
int nj=j+dy[k];
  if(H<=ni||W<=nj||ni<0||nj<0){
  continue;
  }
if(S[ni][nj]=='#'){
A[i][j]=1;
}

}

}
}
int ans=0;
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){  
ans=ans+A[i][j];    

}
}
if(ans==H*W){
cout<<"Yes"<<endl;
} else{
cout<<"No"<<endl;
} 
}
  

