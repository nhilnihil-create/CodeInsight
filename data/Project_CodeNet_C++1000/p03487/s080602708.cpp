#include <iostream>
#include <string>
#include <vector>
#include <map>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  cin >> N;

  std::map<int, int> m;
  rep(i, N) {
    int a;
    cin >> a;
    m[a]++;
  }

  int sum = 0;
  for (const auto& e : m) {
    if (e.first > e.second) sum += e.second;
    else sum += e.second - e.first;
  }

  cout << sum << endl;

  return 0;
}
