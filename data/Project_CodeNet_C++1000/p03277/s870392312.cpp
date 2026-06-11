#include <iostream>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

const int MAX_N = 1e5 + 5;

typedef long long ll;

int n;
int arr [MAX_N];

// # of substrings with median <= x
ll countle (int x) {
  ll ans = 0;
  
  ordered_set<pair<int, int>> pref;
  pref.insert(make_pair(0, -1));
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= x) {
      cur++;
    } else {
      cur--;
    }
    
    ans += pref.order_of_key(make_pair(cur, -10));
    pref.insert(make_pair(cur, i));
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll half = 1 + ((ll) n * (ll) (n + 1) / 2) / 2;

  if (countle(0) >= half) {
    cout << 0 << endl;
    return 0;
  }
  
  int ans = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    if (countle(ans + k) < half) {
      ans += k;
    }
  }
  cout << ans + 1 << endl;
}
