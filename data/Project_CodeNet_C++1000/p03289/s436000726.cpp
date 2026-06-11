#include <iostream>
#include <string>

void PrintAns(bool* flags);

int main() {
  std::string S;
  std::cin >> S;

  // 字符串 S 必须满足如下三个条件:
  //   1. 第一个字符必须是 'A'
  //   2. 在 S 中只出现一次 'C', 且他必须是在第三个与倒数第二个字符之间
  //   3. 所有除了 'A' 和 'C' 之外的字符必须都是小写.
  //   如果满足所有条件, 打印 "AC"; 否则, 打印 "WA"
  bool flags[3] = {true, true, true};

  // [TEST 1.]
  if (S[0] != 'A') {
    puts("WA");
    return 0;
  }

  // [TEST 2.]
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

  // [TEST 3.]
  bool flag = true;
  for (int i = 0; i < S.length(); i++) {
    if (i == 0 || S[i] == 'C') continue;  // Exclude TEST1 && TEST2
    if (S[i] >= 'a' && S[i] <= 'z')
      ;
    else {
      flag = false;
      break;
    }
  }
  if (flag)
    puts("AC");
  else
    puts("WA");

  return 0;
}
