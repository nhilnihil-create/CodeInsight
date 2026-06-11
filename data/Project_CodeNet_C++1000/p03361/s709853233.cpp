#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
 
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (data.at(i).at(j) == '#'){
        if (i == 0 && j == 0){
          if (data.at(i+1).at(j) == '.' && data.at(i).at(j+1) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (i == 0 && j == W-1){
          if (data.at(i+1).at(j) == '.' && data.at(i).at(j-1) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (i == H-1 && j == 0){
          if (data.at(i-1).at(j) == '.' && data.at(i).at(j+1) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (i == H-1 && j == W-1){
          if (data.at(i-1).at(j) == '.' && data.at(i).at(j-1) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (i == 0){
          if (data.at(i).at(j+1) == '.' && data.at(i).at(j-1) == '.' && data.at(i+1).at(j) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (j == 0){
          if (data.at(i).at(j+1) == '.' && data.at(i-1).at(j) == '.' && data.at(i+1).at(j) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (i == H-1){
          if (data.at(i).at(j+1) == '.' && data.at(i).at(j-1) == '.' && data.at(i-1).at(j) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else if (j == W-1){
          if (data.at(i).at(j-1) == '.' && data.at(i-1).at(j) == '.' && data.at(i+1).at(j) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
        else {
          if (data.at(i).at(j-1) == '.' && data.at(i).at(j+1) == '.' &&data.at(i-1).at(j) == '.' && data.at(i+1).at(j) == '.'){
            cout << "No" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
}
          
 
  