#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  vector<int> N(4);
  rep(i, 4) cin >> N[i];
  sort(N.begin(), N.end());
  if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
