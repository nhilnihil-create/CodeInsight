#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  vector<vector<char>> vec(3,vector<char>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>vec[i][j];
    }
  }
  
  cout<<vec[0][0]<<vec[1][1]<<vec[2][2]<<endl;
}