#include <iostream>
#include <string>

int decimal(int a){
  int ans = 0;
  while(a > 0) {
    ans += a % 10;
    a = a / 10;
  }
  return ans;
}

int main () {
  int x;
  std::string ans = "No";
  std::cin >> x;
  int fx = decimal(x);
  if(x % fx == 0) ans = "Yes";
  std::cout << ans << std::endl;
}