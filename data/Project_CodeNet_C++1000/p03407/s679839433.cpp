#include <iostream>
#include <string>

int main () {
  int a, b, c;
  std::string ans = "No";
  std::cin >> a >> b >> c;
  if(a + b >= c) ans = "Yes";
  std::cout << ans << std::endl;
}
