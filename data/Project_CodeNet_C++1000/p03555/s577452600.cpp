#include<bits/stdc++.h>
using namespace std;
int main(){
  string x,z;
  cin>>x>>z;
  if(x.at(0)!=z.at(2)) cout<<"NO"<<endl;
  else if(x.at(1)!=z.at(1)) cout<<"NO"<<endl;
  else if(x.at(2)!=z.at(0)) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}