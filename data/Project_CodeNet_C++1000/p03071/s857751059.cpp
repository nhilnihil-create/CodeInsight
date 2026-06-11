#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y;
  cin >> X >> Y;

  int ans=0;
  int i=0;
  while(i<2){
    if(X>Y){
      ans=ans+X;
      X=X-1;
    }
    else{
      ans=ans+Y;
      Y=Y-1;
    }
  i++;
  }

  cout << ans << endl;

return 0;  
}