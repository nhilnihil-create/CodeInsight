#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<char>> A (2,vector<char>(3,'a'));
  
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      cin >> A.at(i).at(j);
    }
  }
  bool B = false;
  for(int j=0;j<3;j++){
    int i=0;
    if(A.at(i).at(j) != A.at(i+1).at(2-j)){
      B=true;
      break;
    }
  }
  if(B){
    cout << "NO" << endl;
  }
  else{
    cout << "YES" << endl;
  }
}