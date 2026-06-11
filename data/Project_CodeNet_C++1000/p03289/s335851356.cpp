#include <iostream>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  // 字符串 S 必须满足如下三个条件:
  //  1. 第一个字符必须是 'A'
  //  2. 在 S 中只出现一次 'C', 且他必须是在第三个与倒数第二个字符之间
  //  3. 所有除了 'A' 和 'C' 之外的字符必须都是小写.
  //  e. 如果满足所有条件, 打印 "AC"; 否则, 打印 "WA"

  // -------- Test1 --------
  if (S[0] != 'A') {
    puts("WA");
    return 0;
  }

  // -------- Test2 --------
  if (S[1] == 'C' || S.back() == 'C') {
    puts("WA");
    return 0;
  }
  int count_c = 0;
  for (int i = 2; i < S.length() - 1; i++)
    if (S[i] == 'C') count_c++;
  if (count_c != 1) {
    puts("WA");
    return 0;
  }

  // -------- Test3 --------
  S = S.substr(1);  // Exclude Test1
  for (char c : S) {
    if (c == 'C') continue;  // Exclude Test2
    if (isupper(c)) {
      puts("WA");
      return 0;
    }
  }

  // Pass all test
  puts("AC");

  return 0;
}
