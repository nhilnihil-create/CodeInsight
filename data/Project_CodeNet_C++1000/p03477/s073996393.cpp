#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int x,y;
  x = a + b;
  y = c + d;
  if(x > y) puts("Left");
  else if(x < y) puts("Right");
  else puts("Balanced");
  return 0;
}
