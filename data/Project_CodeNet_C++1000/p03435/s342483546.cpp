#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  bool can=true;
  int c[3][3];
  for(int i=0; i<3; ++i){
    for(int j=0; j<3; ++j){
      cin >> c[i][j];
    }
  }

  for(int i=0; i<2; ++i){
    int over;
    if(i==2){
      over=-1;
    }else{
      over=i;
    }
    if(c[0][i] - c[0][over+1] != c[1][i] - c[1][over+1] || c[0][i] - c[0][over+1] != c[2][i] - c[2][over+1]){
      can=false;
    }
  }
  
  if(can){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}

