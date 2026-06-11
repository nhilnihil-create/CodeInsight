#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >>a>>b>>c>>d;
  int w,x,y,z;
  
  x=d+c-a;
  w=c-(d-b);
  
  y=a-(d-b);
  z=b+c-a;
  
  cout <<w << ' ' << x << ' ' << y <<' ' << z << endl;
}