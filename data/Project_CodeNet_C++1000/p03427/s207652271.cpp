#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  long long N;
  cin >> N;

  if (N < 10) {
    cout << N << endl;
    return 0;
  }

  string s = to_string(N);

  for (int i = 1; i < s.size(); ++i) {
    if (s[i] != '9') {
      long long ret = 0;
      int n = 1;
      if (i - 1 == 0)
        ret += s[0] - '0' - 1;
      else {
        ret += s[i - 1] - '0' - 1;
        ret += s[0] - '0';
        n = 2;
      }
      ret += 9 * (s.size() - n);
      cout << ret << endl;
      return 0;
    }
  }

  long long ret = s[0] - '0' + 9 * (s.size() - 1);
  cout << ret << endl;

  return 0;
}