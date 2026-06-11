#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

 
int main() {
  int h,w;
  cin >> h >> w;
  
  char S[h+2][w+2];
  rep(i,h+2){
    rep(j,w+2){
      S[i][j] = '0';
    }
  }
  
  char nyu[h][w];
  rep(i,h){
    rep(j,w){
      cin >> nyu[i][j];
    }
  }
  
  rep(i,h){
    rep(j,w){
    S[i+1][j+1] = nyu[i][j];
    }
  }
  
  
  
  
    
    
  rep(i,h+2){
	rep(j,w+2){
      	
      	int n = 0;
      	if(S[i][j] == '#'){
          continue;
        }
      	if(S[i-1][j-1] == '#'){
          n++;
        }
        if(S[i][j-1] == '#'){
          n++;
        }
        if(S[i+1][j-1] == '#'){
          n++;
        }
        if(S[i-1][j] == '#'){
          n++;
        }
        if(S[i][j+1] == '#'){
          n++;
        }
        if(S[i+1][j] == '#'){
          n++;
        }
        if(S[i+1][j+1] == '#'){
          n++;
        }
        if(S[i-1][j+1] == '#'){
          n++;
        }
        S[i][j] = n + '0';
     }
  }
  
  rep(i,h+2){
	rep(j,w+2){
      if(i != 0 && i != h+1 && j != 0 && j != w+1){ 
        cout << S[i][j];
      }
    }
    if(i != 0 && i != h+1 )
  	cout << endl;
  }
  
  
  
  
}