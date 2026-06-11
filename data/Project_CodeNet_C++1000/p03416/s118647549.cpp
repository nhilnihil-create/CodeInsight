#include<bits/stdc++.h>
using namespace std;
int main(){
  int y,z,x,w,ans;
  cin>>y>>z;
  x=y/100;
  w=z/100;
  ans=w-x+1;
  if(100*x+10*(y/1000%10)+y/10000<y) ans--;
  if(100*w+10*(z/1000%10)+z/10000>z) ans--;
  cout<<ans<<endl;
}