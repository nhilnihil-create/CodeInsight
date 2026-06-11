#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;cin>>H>>W;
  string A[H];
  for(int i=0;i<H;i++) cin>>A[i];
  char ans[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]=='#') ans[i][j]='#';
      else{
        int count=0;
        int up=max(0,i-1);
        int down=min(i+1,H-1);
        int left=max(0,j-1);
        int right=min(j+1,W-1);
        for(int k=up;k<=down;k++){
          for(int l=left;l<=right;l++){
            if(k==i && l==j) continue;
            if(A[k][l]=='#') count++;
          }
        }
        ans[i][j]=count+'0';
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cout<<ans[i][j];
    cout<<"\n";
  }
}