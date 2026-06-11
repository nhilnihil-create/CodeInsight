#include "iostream"
#include "algorithm"
#include "vector"

int main(int argc, char const *argv[]) {
  /*
  input
  6 1

  input 2
  7 8

  input 2
  3 5

   */

   int a, b;
   std::cin >> a >> b;

   if (a + b == 15)
   {
     /* code */
     std::cout << "+" << '\n';
   }
   else
   {
     if(a*b == 15)
     {
       std::cout << "*" << '\n';
     }
     else
     {
       std::cout << "x" << '\n';
     }
   }

  return 0;
}
