#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1,y1,x2,y2,x,y;
  cin>>x1>>y1>>x2>>y2;
  x=y2-y1,y=x1-x2;
  cout<<x2-x<<" "<<y2-y<<" "<<x1-x<<" "<<y1-y;
}
