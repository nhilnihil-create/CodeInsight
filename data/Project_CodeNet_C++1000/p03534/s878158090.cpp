#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  string S;
  while (cin >> S) {
    vector<int> cnt(3, 0);
    for (char c : S) ++cnt[c - 'a'];
    int m = min({cnt[0], cnt[1], cnt[2]});
    bool res = cnt[0] - m <= 1 && cnt[1] - m <= 1 && cnt[2] - m <= 1;
    cout << (res ? "YES" : "NO") << endl;
  }
  return 0;
}
