#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int A,B,C,X,Y;

  cin >> A >> B >> C >> X >> Y ;

  int64_t ans=1000000000;

  for(int i=0;i<=100000;i++){
    
    int64_t sum = 2*C*i + A*max(0,X-i) + B*max(0,Y-i);

    if(ans>sum) ans = sum;

  }

   cout << ans << endl;
    
  return 0;
}