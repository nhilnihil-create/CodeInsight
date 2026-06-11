#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

const int N = 200005;

int n;
int arr[N];

bool ok(int x) {
  map <int, int> cnt;
  for (int i = 1; i < n; i++) {
    if (arr[i] <= arr[i - 1]) {
      int ce = arr[i];
      while (!cnt.empty() && (--cnt.end())->first > ce) {
        cnt.erase(--cnt.end());
      }
      cnt[ce]++;
      while (cnt[ce] >= x) {
        cnt.erase(ce--);
        cnt[ce]++;
        if (ce == 0) return 0;
      }
    }
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bool ww = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] <= arr[i - 1]) {
      ww = 0;
    }
  }
  if (ww) {
    cout << 1 << endl;
    return 0;
  }
  int l = 2, r = 1e9, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
