#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
/***** MAIN *****/
signed main() {
  int n;
  cin >> n;
  int cur_power[n];
  vector<int> extra_power;
  int shorten_total = 0;
  REP(i,n) {
    cin >> cur_power[i];
  }
  ll ans = 0;
  REP(i,n) {
    int nece_power;
    cin >> nece_power;
    int diff = cur_power[i] - nece_power;
    if(diff == 0) continue;
    if(diff > 0) {
      extra_power.PB(diff);
    } else {
      shorten_total -= diff;
      ++ans;
    }
  }

  SORTR(extra_power);
  REP(i,extra_power.size()) {
    if(shorten_total <= 0) break;
    shorten_total -= extra_power[i];
    ++ans;
  }
  if(shorten_total <= 0) {
    cout << ans;
  } else {
    cout << -1;
  }
  
  cout << "\n";
  return 0;
}
/***** MAIN *****/
