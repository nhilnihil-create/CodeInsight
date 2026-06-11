#include <bits/stdc++.h>
using namespace std;

int main(){
int n,w;
  cin >> n >> w;
string d[50];
  for(int i=0;i<n;i++) cin >> d[i];
 int dx[8]={1,0,-1,0,1,1,-1,-1};
 int dy[8]={0,-1,0,1,1,-1,-1,1};
for(int i=0;i<n;i++){
  for(int j=0;j<w;j++){
    
    if(d[i][j]=='#')continue;
    int num=0;
    for(int k=0;k<8;k++){
     int x=j+dx[k];
     int y=i+dy[k];        
    if(x<0 | w<=x)continue;
    if(y<0 | n<=y)continue;
    if(d[y][x]=='#')num++;      
    }
    d[i][j]=char(num+'0');
  }
}  
for(int i=0;i<n;i++) cout << d[i] << endl;
  
  
}
