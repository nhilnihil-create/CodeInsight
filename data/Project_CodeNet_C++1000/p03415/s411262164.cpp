#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<vector<char>> c(3,vector<char>(3));
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin>>c.at(i).at(j);
  for(int i=0;i<3;i++)
    cout<<c.at(i).at(i);
  cout<<endl;
}