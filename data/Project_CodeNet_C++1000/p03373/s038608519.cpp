#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int d=a*x+b*y; //baragai
  int e=c*max(x,y)*2; //ABnomi
  int f;
  if(x>y) f=c*y*2+(x-y)*a;
  else f=c*x*2+(y-x)*b;
  cout<<min({d,e,f});

}
