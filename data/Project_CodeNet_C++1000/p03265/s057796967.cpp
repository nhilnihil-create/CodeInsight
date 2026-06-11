#include <bits/stdc++.h>
using namespace std;

int main(){
  double x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  double a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  double x3,y3,x4,y4,X3,Y3,X4,Y4;
  double costheta=(x2-x1)/a;
  double sintheta=(y2-y1)/a;
  X3=a;
  Y3=a;
  X4=0;
  Y4=a;
  x3=X3*costheta-Y3*sintheta+x1;
  y3=X3*sintheta+Y3*costheta+y1;
  x4=X4*costheta-Y4*sintheta+x1;
  y4=X4*sintheta+Y4*costheta+y1;
  cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;
}