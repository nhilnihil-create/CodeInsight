#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<char> > x(3,vector<char>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>x[i][j];
    }
  }
  for(int i=0;i<3;i++){
    cout<<x[i][i];
  }
}