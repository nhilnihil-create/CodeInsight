#include<bits/stdc++.h>
using namespace std;
int main(){
  int z;
  char c;
  string x="Three";
  cin>>z;
  for(int y=0;y<z;y++){
    cin>>c;
    if(c=='Y') x="Four";
  }
  cout<<x<<endl;
}