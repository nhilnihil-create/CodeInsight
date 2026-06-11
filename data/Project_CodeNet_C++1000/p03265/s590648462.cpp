#include <bits/stdc++.h>
using namespace std;

int main(){
  int ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  
  int p = bx - ax, q = ay - by;
  cout << bx+q << ' ' << by+p << ' ' << ax+q << ' ' << ay+p << endl;
}