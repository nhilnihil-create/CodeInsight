#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> counter(n);
  for (int i = 0; i < n-1; i++) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      if (i == 0) {
        counter[i]++;
      } else {
        counter[i] = counter[i-1] + 1;
      }
    } else {
      if (i == 0) {
        counter[i] = 0;
      } else {
        counter[i] = counter[i-1];
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int l, r, ans;
    cin >> l >> r;
    l--;
    r--;

    if (l == 0) {
      cout << counter[r-1] << endl;
    } else {
      cout << counter[r-1] - counter[l-1] << endl;
    }
  }
}