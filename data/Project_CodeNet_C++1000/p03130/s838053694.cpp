#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  vector<int> degree(4);
  for (int i = 0; i < 3; ++i) {
    int a, b;
    cin >> a >> b;
    degree[a - 1]++;
    degree[b - 1]++;
  }
  sort(degree.begin(), degree.end());
  bool ok = degree[0] == 1 && degree[1] == 1 && degree[2] == 2 && degree[3] == 2;
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
