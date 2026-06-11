#include <iostream>

int main(){
  char s[3];
  int sum = 700;
  for (int i = 0; i < 3; i++){
    std::cin >> s[i];
    if (s[i] == 'o')
      sum += 100;
  }
  std::cout << sum << std::endl;
  return 0;
}