#include<bits/stdc++.h>
using namespace std;
int main(){
  string g;
  cin>>g;
  if(g.at(0)==g.at(1)&&g.at(0)==g.at(2)) cout<<"Yes"<<endl;
  else if(g.at(1)==g.at(2)&&g.at(1)==g.at(3)) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}