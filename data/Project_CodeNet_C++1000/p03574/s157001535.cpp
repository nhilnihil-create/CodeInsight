#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> str(H);
  for (int i = 0; i < H; i++){
    cin >> str[i];
  }
  
  string s;
  int count;
  
  for (int i = 0; i < H; i++){
    
    for (int j = 0; j < W; j++){
      if (str[i][j] == '#'){
        continue;
      }
      
      count = 0;
      
      if (i > 0 && j > 0){
        if (str[i-1][j-1] == '#'){
          count++;
        }
      }
      
      if (i > 0){
        if (str[i-1][j] == '#'){
          count++;
        }
      }
      
      if (i > 0 && j < (W-1)){
        if (str[i-1][j+1] == '#'){
          count++;
        }
      }
      
      if (j > 0){
        if (str[i][j-1] == '#'){
          count++;
        }
      }
      
      if (j < (W-1)){
        if (str[i][j+1] == '#'){
          count++;
        }
      }
      
      if (i < (H-1) && j > 0){
        if (str[i+1][j-1] == '#'){
          count++;
        }
      }
      
      if (i < (H-1)){
        if (str[i+1][j] == '#'){
          count++;
        }
      }
      
      if (i < (H-1) && j < (W-1)){
        if (str[i+1][j+1] == '#'){
          count++;
        }
      }
      
      str[i][j] = char(count + '0');
    }
  }
  
  for (int i = 0; i < H; i++){
    cout << str[i] << endl;
  }
  
}
