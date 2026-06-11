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
  int N;
  cin >> N;

  vector<string> S(N);
  rep(i, N) cin >> S[i];

  rep(i, N - 1)
  {
    if (S[i][S[i].size() - 1] != S[i + 1][0])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  std::sort(S.begin(), S.end());
  rep(i, N - 1)
  {
    if (S[i] == S[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
