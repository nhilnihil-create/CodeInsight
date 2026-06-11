#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  int I,J;
  cin >> a >> b >> c >> x >> y;
  int rel = 10000000;
  if(a+b < c*2){
    I = a*x+b*y;
    
  }
  else{
    I = c*min(x,y)*2 + (a*(x-min(x,y)) + b*(y-min(x,y)));
    J = c*max(x,y)*2;
    I = min(I,J);
  }

  cout << I << endl;
}
