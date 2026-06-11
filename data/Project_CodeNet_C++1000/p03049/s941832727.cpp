#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  vector<string> s(N);
  for (int i = 0; i < N; ++i)
    cin >> s[i];

  long long ret = 0;
  long long start_with_b = 0;
  long long end_with_a = 0;
  long long both = 0;
  for (int i = 0; i < N; ++i) {
    if (s[i].front() == 'B' && s[i].back() == 'A')
      ++both;
    else if (s[i].front() == 'B')
      ++start_with_b;
    else if (s[i].back() == 'A')
      ++end_with_a;
    for (int j = 0; j < s[i].size() - 1; ++j) {
      if (s[i].substr(j, 2) == string("AB"))
        ++ret;
    }
  }

  if (both > 0) {
    ret += both - 1;
    N = N - both + 1;
    if (start_with_b > 0 && end_with_a > 0) {
      ret += 2;
      --start_with_b;
      --end_with_a;
      N -= 2;
    } else if (start_with_b > 0) {
      ++ret;
      --start_with_b;
      N -= 1;
    } else if (end_with_a > 0) {
      ++ret;
      --end_with_a;
      N -= 1;
    }
  }
  if (N > 1)
    ret += min(start_with_b, end_with_a);

  cout << ret << endl;

  return 0;
}