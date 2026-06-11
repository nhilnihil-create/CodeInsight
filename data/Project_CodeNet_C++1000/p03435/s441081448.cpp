#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<vector<int>> c(3, vector<int>(3));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> c.at(i).at(j);
    }
  }
  bool takahashi = true;
  vector<int> dif(3);
  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      dif.at(j) = c.at(i).at(j)-c.at(i+1).at(j);
    }
    if(dif.at(0)!=dif.at(1) || dif.at(1)!=dif.at(2)){
      takahashi = false;
      break;
    }
    for(int j=0; j<3; j++){
      dif.at(j) = c.at(j).at(i)-c.at(j).at(i+1);
    }
    if(dif.at(0)!=dif.at(1) || dif.at(1)!=dif.at(2)){
      takahashi = false;
      break;
    }
  }
  if(takahashi){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}