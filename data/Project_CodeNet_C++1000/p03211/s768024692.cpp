#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  int L = S.size();
  int vmin = 1e9;
  for (int i = 0; i + 2 < L; ++i) {
    int v = stoi(S.substr(i, 3));
    vmin = min(vmin, abs(753 - v));
  }
  cout << vmin << endl;
}
