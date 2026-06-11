#include<iostream>
using namespace std;
int main(){

  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  int xdis=(x2-x1);
  int ydis=(y2-y1);
  int x3=x2-ydis;
  int y3=y2+xdis;
  int x4=x1-ydis;
  int y4=y1+xdis;
  cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
  return 0;
}