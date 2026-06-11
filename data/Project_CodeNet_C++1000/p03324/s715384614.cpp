#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main () {
   int d, n; cin >> d >> n;

   int ans;
   if(d == 0) {
      ans = n;
   } else if(d == 1){
      ans = 100*n;
   } else {
      ans = 10000*n;
   }

   if(n == 100) {
      if(d == 0) {
         ans = n + 1;
      } else if(d == 1) {
         ans = 100*n + 100;
      } else {
         ans = 10000*n + 10000;
      }
   }

   cout << ans << endl;
}