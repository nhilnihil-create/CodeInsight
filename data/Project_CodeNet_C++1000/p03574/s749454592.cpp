#include <bits/stdc++.h>
using namespace std;

int main()
{
  int h,w; //h side w vertical
  cin >> h >> w;
  
  char s[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){ 
      cin >> s[i][j];
    }
  }
   
  int con[h][w];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      con[i][j] = 0;
    }
  }
  
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#'){
        if(con[i-1][j-1] != '#' && i != 0 && j != 0){
          con[i-1][j-1]++;
        }
        if(con[i-1][j] != '#' && i != 0){
          con[i-1][j]++;
        }
        if(con[i-1][j+1] != '#' && i != 0 && j != w-1){
          con[i-1][j+1]++;
        }
        if(con[i][j-1] != '#' && j != 0){
          con[i][j-1]++;
        }
        if(con[i][j+1] != '#' && j != w-1){
          con[i][j+1]++;
        }
        if(con[i+1][j-1] != '#' && i != h-1 && j != 0){
          con[i+1][j-1]++;
        }
        if(con[i+1][j] != '#' && i != h-1){
          con[i+1][j]++;
        }
        if(con[i+1][j+1] != '#' && i != h-1 && j != w-1){
          con[i+1][j+1]++;
        }
      }//if
    }//for
  }//for
  
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s[i][j] == '#'){
        cout << s[i][j];
      }else{
        cout << con[i][j];
      }//else
    }//for
    cout << endl;
  }//for
  
}