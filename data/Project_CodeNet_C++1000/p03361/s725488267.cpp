#include <iostream>
#include <string>
#include <vector>

int main(){
   int H, W;
   std::cin >> H >> W;
   std::vector<std::string> s(H);
   for (int i=0; i<H; i++){
      std::cin >> s.at(i);
   }
   std::vector<std::vector<char>> s2(H+2, std::vector<char>(W+2));
   for (int i=0; i<H+2; i++){
      for (int j=0; j<W+2; j++){
         if ((i == 0) || (i == H+1)){
            s2.at(i).at(j) = '.';
         } else if ((j == 0) || (j == W+1)){
            s2.at(i).at(j) = '.';
         } else {
            s2.at(i).at(j) = s.at(i-1).at(j-1);
         }
      }
   }

   for (int i=0; i<H+2; i++){
      for (int j=0; j<W+2; j++){
         std::cerr << s2.at(i).at(j) << " ";
      }
      std::cerr << std::endl;
   }

   bool flag = true;
   for (int i=1; i<H+1; i++){
      for (int j=1; j<W+1; j++){
         if (s2.at(i).at(j) == '#'){
            if (!((s2.at(i-1).at(j) == '#') ||
                  (s2.at(i+1).at(j) == '#') ||
                  (s2.at(i).at(j-1) == '#') ||
                  (s2.at(i).at(j+1) == '#'))){
               flag = false;
               break;
            }
         }
      }
   }

   if (flag)
      std::cout << "Yes" << std::endl;
   else
      std::cout << "No" << std::endl;

}
