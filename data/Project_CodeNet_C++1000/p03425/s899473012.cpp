#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  copy_n(istream_iterator<string>(cin), N, S.begin());
  int64_t m[256] = {0};
  for (auto& item : S) {
    ++(m[static_cast<string::size_type>(item[0])]);
  }

  int64_t result = 0;
  result += (m['M'] * m['A'] * m['R']                  );
  result += (m['M'] * m['A']          * m['C']         );
  result += (m['M'] * m['A']                   * m['H']);
  result += (m['M']          * m['R'] * m['C']         );
  result += (m['M']          * m['R']          * m['H']);
  result += (m['M']                   * m['C'] * m['H']);
  result += (         m['A'] * m['R'] * m['C']         );
  result += (         m['A'] * m['R']          * m['H']);
  result += (         m['A']          * m['C'] * m['H']);
  result += (                  m['R'] * m['C'] * m['H']);
  cout << result << endl;
  return 0;
}
