#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  string str;
  
  cin >> h >> w;
  
  vector<vector<string>> vec(h+2, vector<string>(w+2));
  
  for(int i = 0; i < h+2; i++){
    if(i == 0 || i == h+1){
      for(int j = 0; j < w+2; j++){
       vec.at(i).at(j) = "."; 
      }
    }else{
      cin >> str;
      for(int j = 0; j < w+2; j++){
        if(j == 0 || j == w+1){
          vec.at(i).at(j) == ",";
        }else{
          vec.at(i).at(j) = str.substr(j-1,1);
        }
      }
    }
  }
  
  int cnt;
  for(int i = 1; i < h; i++){
    for(int j = 0; j < w; j++){
      cnt = 0;
      if(vec.at(i).at(j) == "#"){
        if(vec.at(i-1).at(j) == "#") cnt++;
        else if(vec.at(i).at(j-1) == "#") cnt++;
        else if(vec.at(i).at(j+1) == "#") cnt++;
        else if(vec.at(i+1).at(j) == "#") cnt++;
        
        if(cnt == 0){
          cout << "No";
          return 0;
        }
      }
    }
  }
  
  cout << "Yes";
}
