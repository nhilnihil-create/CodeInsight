#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> components;

  int l = 1;
  int r = n - n % 2;
  while (l < r) {
    components.push_back({l, r});
    l++;
    r--;
  }

  if (n % 2 == 1) {
    components.push_back({n});
  }

  vector<pair<int, int>> result;
  for (int i = 0; i < components.size(); ++i) {
    if (i == components.size() -1 && components.size() == 2) continue;
    auto c1 = components[i];
    auto c2 = components[(i + 1) % components.size()];
    for (int u : c1) for (int v : c2) {
      result.push_back({u, v});
    }
  }
  cout << result.size() << endl;
  for (auto p : result) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
