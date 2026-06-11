#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<ll, ll> seen;
  seen[0] = 1;
  ll pref = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    pref += arr[i];

    if (!seen.count(pref)) {
      seen[pref] = 0;
    }

    ans += seen[pref];
    seen[pref]++;
  }

  cout << ans << endl;
}
