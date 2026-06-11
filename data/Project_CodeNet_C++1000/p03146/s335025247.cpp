#include <iostream>
#include <map>

int main(){
   int s;
   std::cin >> s;
   int i = 1;
   std::map<int, int> mp;
   mp[s]++;
   while (true){
      if (s % 2 == 0){
         s = s / 2;
      } else{
         s = 3 * s + 1;
      }
      if (mp[s] == 0){
         mp[s]++;
      } else{
         break;
      }
      i++;
   }
   std::cout << i+1 << std::endl;

}

