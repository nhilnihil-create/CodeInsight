#include <iostream>

int main(void)
{
  int A,B,C;
  std::cin>>A>>B>>C;
  if((A==B)&&(B==C)&&(C==A))
  {
    std::cout<<"Yes"<<std::endl;
  }
  else
    std::cout<<"No"<<std::endl;
}