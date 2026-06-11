#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N, K;
  cin >> N >> K;
  K--;
  string S;
  cin >> S;
  rep(i, S.size())
  {
    if (i == K)
      cout << char(S[i] - 'A' + 'a');
    else
      cout << S[i];
  }
  cout << endl;

  return 0;
}
