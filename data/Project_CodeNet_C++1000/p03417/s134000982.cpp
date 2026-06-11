#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t y,z;
  cin>>y>>z;
  if(y==1&&z==1) cout<<1<<endl;
  else if(y==1) cout<<z-2<<endl;
  else if(z==1) cout<<y-2<<endl;
  else cout<<(y-2)*(z-2)<<endl;
}