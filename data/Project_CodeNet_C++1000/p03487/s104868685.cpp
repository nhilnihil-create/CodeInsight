#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int N;

int main(int argc, char* argv[]) {
  cin >> N;

  unordered_map<int, int> map;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (map.find(a) != map.cend()) {
      map[a]++;
    } else {
      map[a] = 1;
    }
  }

  int res = 0;
  for (auto pair : map) {
    if (pair.first < pair.second)
      res += pair.second - pair.first;
    else if (pair.first > pair.second)
      res += pair.second;
  }
  cout << res << endl;

  return 0;
}
