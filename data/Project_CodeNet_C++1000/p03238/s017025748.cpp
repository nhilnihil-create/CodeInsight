#include <iostream>

using namespace std;

int main(){
  int n;
  std::cin >> n;
  if(n == 1){
    std::cout << "Hello World" << '\n';
  }else{
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
  }
  return 0;
}
