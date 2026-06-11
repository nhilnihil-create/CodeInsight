#include<bits/stdc++.h>
using namespace std;
int main(){
  int y,z;
  cin>>y>>z;
  cout<<max(max(y+z,y-z),y*z)<<endl;
}