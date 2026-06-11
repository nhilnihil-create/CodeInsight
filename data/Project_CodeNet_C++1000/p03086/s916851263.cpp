#include <iostream>
#include <string>

int main()
{
  std::string str;
  std::cin >> str;
  int cnt = 0;
  int max_cnt = 0;
  for (int i=0; i<str.length(); i++) {
    if (str[i] != 'A' && str[i] != 'C' && str[i] != 'G' && str[i] != 'T') cnt = 0;
    else { cnt++; max_cnt = std::max(max_cnt, cnt); }
  }
  std::cout << max_cnt << std::endl;
  return 0;
}