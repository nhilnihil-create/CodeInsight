#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t x,y,z=0;
  cin>>x>>y;
  while(x<=y){
    z++;
    x*=2;
  }
  cout<<z<<endl;
}