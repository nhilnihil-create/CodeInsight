#include<bits/stdc++.h>
using namespace std;
int main(){
  int x=1,y,z,i;
  cin>>y>>z;
  for(i=0;i<y;i++) x=min(2*x,x+z);
  cout<<x<<endl;
}