#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct item {
  int id;
  string address;
  int score;
};

int main() {
  int n;
  cin >> n;
  vector<item> vec;
  for (int i = 1; i <= n; ++i) {
    string s;
    int p;
    cin >> s >> p;
    vec.push_back({i, s, p});
  }

  sort(vec.begin(), vec.end(), [](auto const &lhs, auto const &rhs) {
    return (lhs.address != rhs.address) ? lhs.address < rhs.address
                                          : lhs.score > rhs.score;
  });

  for (auto &v : vec)
    cout << v.id << endl;
}