#include <iostream>

using namespace std;

int main(){
  int a, b;
  std::cin >> a >> b;
  if(a <= 8 && b <= 8){
    std::cout << "Yay!" << '\n';
  }else{
    std::cout << ":(" << '\n';
  }
  return 0;
}
