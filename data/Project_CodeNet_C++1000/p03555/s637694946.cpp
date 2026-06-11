#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string n,m;
  cin>>n>>m;
  if(n.at(0)==m.at(2)&&n.at(1)==m.at(1)&&n.at(2)==m.at(0)){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
