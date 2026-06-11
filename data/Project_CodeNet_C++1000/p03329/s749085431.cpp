#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> m(1000001, 1000000);

int main() {
  int N;
  cin >> N;
  vector<int> v;
  v.push_back(1);
  for (int i = 6; i <= N; i *= 6) v.push_back(i);
  for (int i = 9; i <= N; i *= 9) v.push_back(i);
  sort(begin(v), end(v));

  m[0] = 0;
  for (int i = 1; i <= N; ++i) {
    for (auto a : v) {
      if (i < a) break;
      m[i] = min(m[i], m[i - a] + 1);
    }
  }

  cout << m[N] << endl;
}
