#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,z;
  cin>>x;
  for(z=1;z*z<=x;z++){}
  cout<<(z-1)*(z-1)<<endl;
}