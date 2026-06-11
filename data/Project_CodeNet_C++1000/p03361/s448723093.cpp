#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  char s[60][60];
  int dx[4]={1,-1,0,0};
  int dy[4]={0,0,1,-1};
 
  for(int i=0;i<H;i++)  cin >> s[i];
   
  bool ans=true;
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(s[i][j]=='#'){
      bool found =false;
    
        for(int k=0;k<4;k++){
          int i2=i+dx[k];
          int j2=j+dy[k];
          if(i2>=0 && i2<H && j2>=0 && j2<W && s[i2][j2]=='#'){
            found=true;
          }
        }
        if(!found) ans=false;
      }
    }
  }
  
  cout <<(ans ? "Yes":"No")<<endl;

return 0;
}
