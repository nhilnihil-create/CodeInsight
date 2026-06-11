#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> c(9);
  for(int i=0;i<9;i++){
    cin>>c.at(i);
  }
  bool ans=true;
  if(c.at(0)+c.at(4)!=c.at(1)+c.at(3))
    ans=false;
  if(c.at(1)+c.at(5)!=c.at(2)+c.at(4))
    ans=false;
  if(c.at(3)+c.at(7)!=c.at(4)+c.at(6))
    ans=false;
  if(c.at(4)+c.at(8)!=c.at(5)+c.at(7))
    ans=false;
  
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
