#include <iostream>
#include <string>

int main()
{
  std::string S;
  std::cin >> S;
  int ans = 0;
  for (int i = 0; i < S.size(); i++)
  {
    if (S[i] == '+') ans++;
    else ans--;
  }
  std::cout << ans << std::endl;
}
