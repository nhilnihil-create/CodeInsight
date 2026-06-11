#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> c(3,vector<int>(3));
  for(vector<int> &i:c)
    for(int &j:i)
      cin>>j;
  bool bo=true;
  vector<int> vei(2),vej(2);
  for(int i=0;i<2;i++){
    vei.at(i) = c.at(0).at(i) - c.at(0).at(i+1);
    vej.at(i) = c.at(i).at(0) - c.at(i+1).at(0);
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++)
      if(vei.at(j) != c.at(i).at(j) - c.at(i).at(j+1))
        bo=false;
    for(int j=0;j<2;j++)
      if(vej.at(j) != c.at(j).at(i) - c.at(j+1).at(i))
        bo=false;
  }
  if(bo)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}