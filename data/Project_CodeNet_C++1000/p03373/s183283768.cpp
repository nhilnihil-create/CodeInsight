#include <bits/stdc++.h>
using namespace std;

int main () {
  int a,b,c,x,y;
  cin >>a >>b >>c >>x >>y;
  
  int ans = INT_MAX;
  if ((a/2 + b/2)<c)
  {
    ans = a*x + b*y;
  }
  else
  {
    for (int i=0; i<=max(x,y)*2; i++) {
      int tmp = i*2*c + a*max((x-i),0) + b*max((y-i),0);
        if (tmp <ans) ans =tmp;
    }
  }
    cout << ans << endl;
    return 0;
}