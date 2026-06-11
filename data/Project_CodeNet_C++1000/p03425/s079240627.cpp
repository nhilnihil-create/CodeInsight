#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string march("MARCH");

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  copy_n(istream_iterator<string>(cin), N, S.begin());
  unordered_map<char, int64_t> m;
  for (auto& item : S) {
    if (string::npos != march.find_first_of(item[0], 0)) {
      if (m.count(item[0])) ++(m[item[0]]);
      else m[item[0]] = 1;
    }
  }

  int64_t result = 0;
  for (size_t i = 0; i < march.size() - 2; ++i) {
    for (size_t j = i + 1; j < march.size() - 1; ++j) {
      for (size_t k = j + 1; k < march.size(); ++k) {
        result += m[march[i]] * m[march[j]] * m[march[k]];
      }
    }
  }
  cout << result << endl;
  return 0;
}
