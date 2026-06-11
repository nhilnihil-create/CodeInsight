#include<bits/stdc++.h>
using namespace std;
int main(){
  int x1,y1,x2,y2,x3,y3,x4,y4,dx,dy;
  cin>>x1>>y1>>x2>>y2;
  dx=x2-x1;
  dy=y2-y1;
  x3=x2-dy;
  y3=y2+dx;
  x4=x3-dx;
  y4=y3-dy;
  cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;
}