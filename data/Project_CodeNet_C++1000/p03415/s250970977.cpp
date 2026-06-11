#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<char>> A (3,vector<char>(3,'a'));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> A.at(i).at(j);
    }
  }
  for(int i=0;i<3;i++){
    cout << A.at(i).at(i);
  }
  cout << endl;
}