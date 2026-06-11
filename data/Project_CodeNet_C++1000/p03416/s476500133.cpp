#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

int main() {
  int A, B;
  std::cin >> A >> B;
  
  int cnt = 0;
  for (int num = A; num <= B; ++num) {
    std::stringstream ss;
    ss << num;
    
    std::string s = ss.str();
    std::string re = s;
    std::reverse(re.begin(), re.end());
    
    if (s == re) ++cnt;
  }
  std::cout << cnt << std::endl;
}