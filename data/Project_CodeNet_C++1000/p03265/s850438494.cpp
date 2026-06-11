#include<bits/stdc++.h>
using namespace std;

int main(){
  int ax,ay,bx,by;
  cin >> ax >> ay >> bx >> by;
  int cx,cy,dx,dy;
  cx=bx+ay-by;
  cy=by+bx-ax;
  dx=ax+ay-by;
  dy=ay+bx-ax;
  cout << cx << " " << cy << " " << dx << " " << dy << endl;
  return 0;
}