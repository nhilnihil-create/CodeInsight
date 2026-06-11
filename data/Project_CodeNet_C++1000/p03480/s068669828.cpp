#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;

int main(int argc, char* argv[]) {
  cin >> S;

  int res = S.size();
  for (int i = 0; i < S.size() - 1; i++) {
    if (S[i] == S[i + 1])
      continue;

    if (res > max<int>(i + 1, S.size() - i - 1))
      res = max<int>(i + 1, S.size() - i - 1);
  }
  cout << res << endl;

  return 0;
}