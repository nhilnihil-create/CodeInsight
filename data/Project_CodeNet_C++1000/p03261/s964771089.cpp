#include <iostream>
#include <string>
#include <map>

int main(){
   int N;
   std::cin >> N;
   std::map<std::string, int> mp;
   bool flag = true;
   for (int i=0; i<N; i++){
      char next;
      std::string key;
      std::cin >> key;
      if (i == 0){
         mp[key]++;
         next = key.at(key.size()-1);
      } else{
         if (!((key.at(0) == next) && (mp[key] == 0))){
            flag = false;
         } else{
            mp[key]++;
            next = key.at(key.size()-1);
         }
      }
      //std::cerr << next << std::endl;
   }
   if (flag)
      std::cout << "Yes" << std::endl;
   else
      std::cout << "No" << std::endl;

}

