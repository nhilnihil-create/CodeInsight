#include<bits/stdc++.h>
using namespace std;
int main(void){
  int a,b,c,x,y; cin>>a>>b>>c>>x>>y; c*=2;
  cout<<min(a+b,c)*min(x,y)+(x<y? min(b,c):min(a,c))*abs(x-y);
  return 0;
}