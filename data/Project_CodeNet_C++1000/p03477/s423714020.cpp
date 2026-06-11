#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z,w;
  cin>>x>>y>>z>>w;
  if(x+y>z+w) cout<<"Left"<<endl;
  else if(x+y==z+w) cout<<"Balanced"<<endl;
  else if(x+y<z+w) cout<<"Right"<<endl;
}