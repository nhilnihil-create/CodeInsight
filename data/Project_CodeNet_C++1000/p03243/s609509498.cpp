#include <iostream>
#include <string>


int main () {
   int n; std::cin >> n;

   int ans;
   for(int i = 1; i <= 9; i++) {
      if(n <= 111*i) {
         ans = 111*i;
         break;
      }
   }

   std::cout << ans << std::endl;
}
