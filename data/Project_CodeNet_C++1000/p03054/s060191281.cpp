#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  
  int h,w; cin >> h >> w; int n ; cin >> n;
  int sr,sc; cin >> sr >> sc;
  
  string S,T; cin >> S >> T;
  
  sr--; sc--;
  
  int x = sr; int y = sc; 
  
  //右
  for(int i = 0; i < n; i++){
      if( S[i] == 'R'){
        y++; 
        if( y >= w){ cout << "NO" << endl; return 0;}
      }
    
      if( T[i] == 'L'){ 
        if( y > 0){ y--;}
      }
    
  }
  
  x = sr; y = sc; 
  
  //左
  for(int i = 0; i < n; i++){
    
      if( S[i] == 'L'){
        y--; 
        if( y < 0 ){ cout << "NO" << endl; return 0;}
      }
      if( T[i] == 'R'){ 
        if( y < w-1){ y++;}
      }
    
  }
 
  x = sr; y = sc; 
  
  //上
  for(int i = 0; i < n; i++){
    
      if( S[i] == 'U'){
         x--;
        if( x < 0 ){ cout << "NO" << endl; return 0;}
      }
      if( T[i] == 'D'){ 
        if( x < h-1){ x++;}
      }
    
  }
 
  x = sr; y = sc; 
  
  //下
  for(int i = 0; i < n; i++){
      if( S[i] == 'D'){
        x++; 
        if( x >= h){ cout << "NO" << endl; return 0;}
      }
      if( T[i] == 'U'){ 
        if( x > 0){ x--;}
      }
    
  }
 
  
  cout << "YES" << endl;
  
  return 0;
}
  
 
        
                       