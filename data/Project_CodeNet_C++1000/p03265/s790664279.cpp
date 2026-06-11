#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x1,x2,x3,x4,y1,y2,y3,y4;
  cin>>x1>>y1>>x2>>y2;
  x3=x2+y1-y2;
  y3=y2+x2-x1;
  x4=x3+y2-y3;
  y4=y3+x3-x2;
  cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
}  