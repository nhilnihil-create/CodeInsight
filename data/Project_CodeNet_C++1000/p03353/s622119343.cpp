#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string s;
  cin >> s;
  int K;
  cin >> K;

  vector<string> sub;
  rep(i, s.size()) {
    for(int j = 1; j <= K; j++) {
      if (i + j > s.size()) break;
      sub.push_back(s.substr(i, j));
    }
  }

  std::sort(sub.begin(), sub.end());

  int count = 0;
  string before = "";
  rep(i, sub.size()) {
    if (sub[i] != before) {
      count++;
      before = sub[i];

      if (count == K) {
        cout << sub[i] << endl;
        break;
      }
    }
  }

  return 0;
}
