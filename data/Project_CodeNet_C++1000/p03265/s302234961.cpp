#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y,xx,yy;
  cin >> x >> y >> xx >> yy;
  int a=xx-x; int b=yy-y;
  cout << xx-b << " " << yy+a << " ";
  cout << x-b << " " << y+a << endl;
}