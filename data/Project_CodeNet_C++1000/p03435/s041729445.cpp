#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> C(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> C.at(i).at(j);
    }
  }
  int count=0;
  for(int i=0;i<2;i++){
    if(C.at(i+1).at(0)-C.at(0).at(0)==C.at(i+1).at(1)-C.at(0).at(1)
       && C.at(i+1).at(1)-C.at(0).at(1)==C.at(i+1).at(2)-C.at(0).at(2)){
      count++;
    }
  }
  if(count==2){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}