#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,j;
  vector<vector<int>> c(3,vector<int>(3));
  for(i=0;i<3;i++) for(j=0;j<3;j++) cin>>c.at(i).at(j);
  if(c.at(1).at(0)-c.at(0).at(0)!=c.at(1).at(1)-c.at(0).at(1)) cout<<"No"<<endl;
  else if(c.at(1).at(0)-c.at(0).at(0)!=c.at(1).at(2)-c.at(0).at(2)) cout<<"No"<<endl;
  else if(c.at(2).at(0)-c.at(0).at(0)!=c.at(2).at(1)-c.at(0).at(1)) cout<<"No"<<endl;
  else if(c.at(2).at(0)-c.at(0).at(0)!=c.at(2).at(2)-c.at(0).at(2)) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}