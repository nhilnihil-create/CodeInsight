#include <iostream>
#include <cstdlib>

int main () {
  int ans = 0;
  char s;
  for(int i = 0; i < 3; ++i){
    std::cin >> s;
    if(s == '1') ++ans;
  }
  std::cout << ans << std::endl;
}
