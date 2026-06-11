#include<bits/stdc++.h>
using namespace std;
int main(){
  int g;
  cin>>g;
  vector<int64_t> l(87);
  l.at(0)=2;
  l.at(1)=1;
  for(int z=2;z<=g;z++) l.at(z)=l.at(z-1)+l.at(z-2);
  cout<<l.at(g)<<endl;
}