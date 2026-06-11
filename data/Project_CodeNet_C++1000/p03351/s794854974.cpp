#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int x,y,z;
  x=c-a;
  if(x<0){
    x=-x;
  }
  y=c-b;
  if(y<0){
    y=-y;
  }
  z=b-a;
  if(z<0){
    z=-z;
  }
  if(x<=d||y<=d&&z<=d){
    cout<<"Yes";
  }
  else{
    cout<<"No";
  }
}