#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans=0;
  if(a+b<=2*c)ans=a*x+b*y;
  else{
    a=min(a,2*c);
    b=min(b,2*c);
    int dob=min(x,y);
    ans=2*dob*c+a*(x-dob)+b*(y-dob);
  }
  cout << ans;
}

