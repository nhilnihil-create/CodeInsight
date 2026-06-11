#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  std::string s;
  std::cin >> s;
  int sum = 0;
  ll result = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'B')
      sum++;
    else
      result += sum;
  }
  std::cout << result;
  return 0;
}
