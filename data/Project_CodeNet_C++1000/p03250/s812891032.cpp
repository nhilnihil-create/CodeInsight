#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> p(3);
  cin >> p[0] >> p[1] >> p[2];

  sort(p.begin(), p.end(), greater<int>());
  cout << p[0] * 10 + p[1] + p[2] << endl;
  return 0;
}
