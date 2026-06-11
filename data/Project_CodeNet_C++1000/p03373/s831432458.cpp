#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(x<=y)
    cout<<min(a+b,c*2)*x+min(b,c*2)*(y-x)<<endl;
  else
    cout<<min(a+b,c*2)*y+min(a,c*2)*(x-y)<<endl;
}