#include <iostream>
#include <vector>

using namespace std;
int main (){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y ;
  int smaller = min(x,y);
  x -= smaller;
  y -= smaller;
  cout << min(a+b,2*c)*smaller + min(a*x+y*b,max(x,y)*2*c )<< endl;
                                     }                                     
 