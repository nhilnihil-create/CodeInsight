#include <iostream>
#include <string>
#include <cctype>


int main () {
   std::string s; std::cin >> s;
   std::string ans;

   int count = 0;

   int CID = 0;
   if(s[0] == 'A') {
      count ++;
   }

   for(auto i = 2; i <= s.length() - 2; i++) {
      if(s[i] == 'C') {
         count ++;
         CID = i;
      }
   }

   bool isLow = true;


   for(auto i = 1; i < s.length(); i++) {
      if(i != CID) {
         if(std::isupper(s[i])) {
            isLow = false;
         }
      }
   }

   if(isLow && count == 2) {
      ans = "AC";
   } else {
      ans = "WA";
   }

   std::cout << ans << std::endl;
}


   
