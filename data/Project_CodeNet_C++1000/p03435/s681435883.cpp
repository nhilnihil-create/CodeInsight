#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> vec(3, vector<int>(3));
  vector<int> tmp(3);
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> vec.at(i).at(j);
    }
  }
  bool ans = true;
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      tmp.at(j) = vec.at(i).at(j) -vec.at(i + 1).at(j);
    }
    if(tmp.at(0) != tmp.at(1) || tmp.at(1) != tmp.at(2) || tmp.at(2) != tmp.at(0)){
      ans = false;
    }
  }
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      tmp.at(j) = vec.at(j).at(i) -vec.at(j).at(i + 1);
    }
    if(tmp.at(0) != tmp.at(1) || tmp.at(1) != tmp.at(2) || tmp.at(2) != tmp.at(0)){
      ans = false;
    }
  }
  if (ans){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}