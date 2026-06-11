#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  int h,w;
  cin >> h >> w ;
  vector<vector<int>>a(h+1,vector<int>(w+1));
  vector<vector<int>>b(h+1,vector<int>(w+1));
  for(int i=0; i<h; i++){
   for(int j=0; j<w; j++){
     int x;
     cin >> x;
     a[i][j]=x%2;
     b[i][j]=a[i][j];
   }
  }
  
  
  int count = 0;
  for(int i=0; i<h; i++){
   for(int j=0; j<w; j++){
     a[i][j]%=2;
     if(a[i][j]==0) continue;
     if(i==h-1 && j==w-1) break;
     if(i==h-1){
      a[i][j+1]++;
      count++;
     } 
     else if(a[i][j+1]%2==0 || i==h-1){
      a[i+1][j]++;
      count++;
     }
     else{
      a[i][j+1]++;
      count++;
     } 
   }
  }
  
  cout << count << endl;
  
    for(int i=0; i<h; i++){
   for(int j=0; j<w; j++){
     b[i][j]%=2;
     if(b[i][j]==0) continue;
     if(i==h-1 && j==w-1) break;
     if(i==h-1){
      b[i][j+1]++;
      count++;
      cout << i+1 << " " << j+1 << " " << i+1 << " " << j+2 << endl;
     } 
     else if(b[i][j+1]%2==0 || i==h-1){
      b[i+1][j]++;
      count++;
      cout << i+1 << " " << j+1 << " " << i+2 << " " << j+1 << endl;
     }
     else{
      b[i][j+1]++;
      count++;
      cout << i+1 << " " << j+1 << " " << i+1 << " " << j+2 << endl;
     } 
   }
  }
  
  
}
