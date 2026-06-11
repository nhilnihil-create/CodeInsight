#include <iostream>
#include <algorithm>

int main() {
  // 入力
  std::string str;
  std::cin >> str;

  // 逆順にする
  if (str.length() == 3) {
    std::reverse(str.begin(), str.end());
  }

  // 出力
  std::cout << str << std::endl;
  
  return 0;
}
