#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;

  std::map<char, int> m;
  string s;
  rep(i, N) {
    cin >> s;
    switch(s[0]) {
    case 'M':
    case 'A':
    case 'R':
    case 'C':
    case 'H':
      m[s[0]]++;
    }
  }

  std::queue<std::pair<long long, int>> q;
  for (const auto& e : m) {
    int size = q.size();
    rep(i, size) {
      auto p = q.front();
      q.pop();

      q.push(std::make_pair(p.first * e.second, p.second + 1));
      q.push(p);
    }

    q.push(std::make_pair(e.second, 1));
  }

  long long sum = 0;
  while (!q.empty()) {
    auto p = q.front();
    q.pop();

    if (p.second == 3) sum += p.first;
  }

  cout << sum << endl;

  return 0;
}
