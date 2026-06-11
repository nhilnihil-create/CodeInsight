#include <iostream>
#include <vector>

int main(){
    int k;
    std::vector<int> a(5);
    for(auto i = 0; i < 5; i++){
        std::cin >> a.at(i);
    }
    std::cin >> k;

   if(a.at(a.size() - 1) - a.at(0) > k){
       std::cout << ":(" << std::endl;
   }
   else{
       std::cout << "Yay!" << std::endl;
   }

   return 0;
}
