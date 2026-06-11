#include <iostream>
#include <vector>

int main(){
   std::vector<std::vector<int>> c(3, std::vector<int> (3));
   for (int i=0; i<3; i++){
      for (int j=0; j<3; j++){
         std::cin >> c.at(i).at(j);
      }
   }

   int a1, a2, a3, b1, b2, b3;
   for (int i=0; i<3; i++){
      int b1_b2;
      if (i == 0){
         b1_b2 = c.at(i).at(0) - c.at(i).at(1);
      } else{
         if (c.at(i).at(0) - c.at(i).at(1) != b1_b2){
            std::cout << "No" << std::endl;
            return 0;
         }
      }
   }

   for (int i=0; i<3; i++){
      int b1_b3;
      if (i == 0){
         b1_b3 = c.at(i).at(0) - c.at(i).at(2);
      } else{
         if (c.at(i).at(0) - c.at(i).at(2) != b1_b3){
            std::cout << "No" << std::endl;
            return 0;
         }
      }
   }

   for (int i=0; i<3; i++){
      int b2_b3;
      if (i == 0){
         b2_b3 = c.at(i).at(1) - c.at(i).at(2);
      } else{
         if (c.at(i).at(1) - c.at(i).at(2) != b2_b3){
            std::cout << "No" << std::endl;
            return 0;
         }
      }
   }

   for (int i=0; i<3; i++){
      int a1_a2;
      if (i == 0){
         a1_a2 = c.at(0).at(i) - c.at(1).at(i);
      } else{
         if (c.at(0).at(i) - c.at(1).at(i) != a1_a2){
            std::cout << "No" << std::endl;
            return 0;
         }
      }
   }

   for (int i=0; i<3; i++){
      int a1_a3;
      if (i == 0){
         a1_a3 = c.at(0).at(i) - c.at(2).at(i);
      } else{
         if (c.at(0).at(i) - c.at(2).at(i) != a1_a3){
            std::cout << "No" << std::endl;
            return 0;
         }
      }
   }

   for (int i=0; i<3; i++){
      int a2_a3;
      if (i == 0){
         a2_a3 = c.at(1).at(i) - c.at(2).at(i);
      } else{
         if (c.at(1).at(i) - c.at(2).at(i) != a2_a3){
            std::cout << "No" << std::endl;
            return 0;
         }
      }
   }

   std::cout << "Yes" << std::endl;
}

