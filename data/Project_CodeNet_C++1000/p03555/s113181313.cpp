#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<string> c(2);
  for(int i=0;i<2;i++)
    cin>>c.at(i);
  bool f=1;
  for(int i=0;i<2;i++)
    for(int j=0;j<3;j++)
      f=(c.at(i).at(j)!=c.at(1-i).at(2-j)?0:f);
  cout<<(f?"YES":"NO")<<endl;
}