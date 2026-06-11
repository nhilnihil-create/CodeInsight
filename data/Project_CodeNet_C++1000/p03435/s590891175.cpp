#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>>a(3,vector<int>(3));
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cin >> a.at(i).at(j);
  bool ans=true;
  int r1=a.at(0).at(0)-a.at(0).at(1),
  r2=a.at(0).at(1)-a.at(0).at(2);
  for(int i=0;i<3;i++)
    if(a.at(i).at(0)-a.at(i).at(1)!=r1)
      ans=false;
  for(int i=0;i<3;i++)
    if(a.at(i).at(1)-a.at(i).at(2)!=r2)
      ans=false;
  int g1=a.at(0).at(0)-a.at(1).at(0),
  g2=a.at(1).at(0)-a.at(2).at(0);
  for(int i=0;i<3;i++)
    if(a.at(0).at(i)-a.at(1).at(i)!=g1)
      ans=false;
  for(int i=0;i<3;i++)
    if(a.at(1).at(i)-a.at(2).at(i)!=g2)
      ans=false;
  cout << (ans?"Yes":"No") << endl;
  return 0;
}