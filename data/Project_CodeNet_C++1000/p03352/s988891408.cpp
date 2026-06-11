#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 2; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int x;

int main() {
  cin >> x;
  vector<int> v{1};
  rep (i, 32) {
    int j = 2;
    while (pow(i, j) <= x) {
      v.emplace_back(pow(i, j));
      j++;
    }
  }
  sort(v.begin(), v.end());
  cout << *(upper_bound(v.begin(), v.end(), x) - 1) << endl;
  return 0;
}
