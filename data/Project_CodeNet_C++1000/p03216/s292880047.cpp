#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  int Q;
  cin >> Q;

  vector<int> K;
  ll k;
  for (int i = 0; i < Q; ++i) {
    cin >> k;
    K.push_back(k);
  }

  for (int k : K) {
    fprintf(stderr, "k: %d\n", k);
    ll ans = 0;
    map<string, ll> counter;

    for (int i = 0; i < N; ++i) {
      char ch = S[i];

      switch(ch) {
        case 'D':
          counter["D"]++;
          break;
        case 'M':
          counter["M"]++;
          counter["DM"] += counter["D"];
          break;
        case 'C':
          ans += counter["DM"];
          break;
        default:
          // NOOP
          break;
      }

      if (i >= k - 1) {
        char c = S[i - k + 1];

        switch(c) {
          case 'D':
            counter["D"]--;
            counter["DM"] -= counter["M"];
            break;
          case 'M':
            counter["M"]--;
            break;
          default:
            // NOOP
            break;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
