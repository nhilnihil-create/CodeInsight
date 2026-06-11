#include <iostream>

int main(){
   int A, B, C;
   long long int K;
   std::cin >> A >> B >> C >> K;
   if (K % 2 == 0){
      std::cout << A - B << std::endl;
   } else{
      std::cout << B - A << std::endl;
   }
}

