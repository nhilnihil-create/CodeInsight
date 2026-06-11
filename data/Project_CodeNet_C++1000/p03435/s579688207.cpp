#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<vector<int>> c(3,vector<int>(3));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> c.at(i).at(j);
    }
  }
  
  //a0=0
  vector<int> a(3);
  vector<int> b(3);
  a.at(0) = 0;
  for(int i=0; i<3; i++){
    b.at(i) = c.at(0).at(i) - a.at(0);
  }
  for(int i=0; i<3; i++){
    a.at(i) = c.at(i).at(0) - b.at(0);
  }
    
  bool good = true;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(a.at(i) + b.at(j) != c.at(i).at(j)){
        good = false;
      }
    }
  }
    
  if(good == true){
    cout << "Yes" <<endl;
  }
  else{
    cout << "No" << endl;
  }
  
}
