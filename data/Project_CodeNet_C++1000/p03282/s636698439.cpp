#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string S;
  long long K;
  cin >> S >> K;

  int num = 1;
  size_t size = std::min(K, (long long)S.size());
  rep(i, size)
  {
    if (S[i] != '1')
    {
      num = S[i] - '0';
      break;
    }
  }
  cout << num << endl;

  return 0;
}
