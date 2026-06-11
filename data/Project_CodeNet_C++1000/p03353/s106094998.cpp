#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
  string s;
  int K;
  cin >> s >> K;
  set<string> S;
  for (int i = 0, n = s.size(); i != n; ++i) {
    for (int j = 1; j <= K; ++j) {
      if (i + j > n) break;
      string subs = s.substr(i, j);
      S.insert(subs);
    }
  }

  auto it = S.begin();
  advance(it, K - 1);
  cout << *it << endl;
}
