#include <bits/stdc++.h>

int main(void)
{
  std::string num;
  std::cin >> num;

  std::string tmp;
  int ans = 0;

  for (int i = 0; i < (1 << 3); i++) {
    tmp = num[0];
    ans += num[0] - '0';

    for (int j = 0; j < 3; j++) {
      if (i & (1 << j)) {
        tmp += '+';
        tmp += num[j+1];
        ans += num[j+1] - '0';
      }
      else {
        tmp += '-';
        tmp += num[j+1];
        ans -= num[j+1] - '0';
      }
    }
    if (ans == 7) {
      break;
    }
    ans = 0;
  }
  std::cout << tmp << "=7" << std::endl;
  return 0;
}