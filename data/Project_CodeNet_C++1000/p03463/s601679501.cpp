#include <iostream>

using namespace std;

int main(){
  int n, a, b;
  std::cin >> n >> a >> b;

  if((b - a - 1) % 2 == 1){
    std::cout << "Alice" << '\n';
  }else{
    std::cout << "Borys" << '\n';
  }
  return 0;
}
