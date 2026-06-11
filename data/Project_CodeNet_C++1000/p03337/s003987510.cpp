#include <iostream>

int main()
{
  int A, B, aux;

  std::cin >> A >> B;
  aux = A;
  if((A+B) > (A-B) & (A+B) > (A*B)){
     aux = A+B;
    }else{
      if((A-B) > (A+B) & (A-B) > (A*B)){
        aux = A-B;
      }else{
        if((A*B) > (A+B) & (A*B) > (A-B)){
          aux = A*B;
  }}}
        
  std::cout << aux <<std::endl;

  return 0;
}