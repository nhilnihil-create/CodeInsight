#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;cin>>a>>b>>c;
  int x,y,z;
  x=abs(c-a)+abs(c-b);
  y=abs(a-b)+abs(a-c);
  z=abs(b-a)+abs(b-c);
  cout<<min(min(x,y),z)<<endl;
  return 0;

}
