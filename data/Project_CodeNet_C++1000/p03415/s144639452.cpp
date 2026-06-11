#include<bits/stdc++.h>
using namespace std;
int main(){
vector<vector<char>> c(3,vector<char>(3));
  for(int i=0;i<3;i++){
  string S;
    cin>>S;
    for(int j=0;j<3;j++){
  c.at(i).at(j)=S.at(j);
  }
  }
  string s="";
  s+=c.at(0).at(0);
  s+=c.at(1).at(1);
  s+=c.at(2).at(2);
  cout<<s<<endl;
   return 0;
}