#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >>W;
  string s[60];
  int dx[8]={1,1,1,0,0,-1,-1,-1};
  int dy[8]={1,0,-1,1,-1,1,0,-1};
    
  for(int i=0;i<H;i++){
  cin>>s[i];
  }
 
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
     if(s[i][j]=='.'){
      
       int cnt=0;
       for(int k=0;k<8;k++){
         int i2=i+dx[k];
         int j2=j+dy[k];
         if(i2>=0 && i2<H && j2>=0 && j2<W && s[i2][j2]=='#'){
         cnt++;
         }
         s[i][j] = cnt+'0';
       }
     }  
       
      
    }  
  }

  for(int i=0;i<H;i++) cout << s[i] << endl;
return 0;
}
