#include <bits/stdc++.h>
using namespace std;

int main(void){

   long long a, b, c, k;
   cin >> a >> b >> c >> k;
   
   long long ans;
   if (k % 2 == 0){
      ans = a - b;
      if(abs(ans) > 10e18)
         cout << "Unfair" << endl;
      else cout << ans << endl;
      return 0;
   }
   ans = b - a;
   if (abs(ans) > 10e18)
      cout << "Unfair" << endl;
   else cout << ans << endl;
   return 0;

}