#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  
  int x3,y3,x4,y4,d;
  
  x3=x2+y1-y2;
  y3=y2+x2-x1;
  x4=x3+x1-x2;
  y4=y3+y1-y2;
  cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4<<endl;
  
  return 0;
}