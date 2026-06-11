#include <bits/stdc++.h>
using namespace std;

int main(){
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int h,w;
  cin >> h >> w;
string d[50];
  
  for(int i=0;i<h;i++) cin >> d[i];
int num;  
for(int i=0;i<h;i++){
  for(int j=0;j<w;j++){
  if(d[i][j]=='.')continue;
   num=0; 
   for(int k=0;k<4;k++){
    int y=i+dy[k];
    int x=j+dx[k];
   if(y<0 | y>=h)continue;
   if(x<0 | x>=w)continue;
   if(d[y][x]=='#')num++;  
   }
   if(num==0)break; 
  }
  if(num==0)break;
}  
if(num==0)cout << "No" << endl;  
else cout << "Yes" << endl;  
  
}