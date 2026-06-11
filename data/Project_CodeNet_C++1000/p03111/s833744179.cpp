#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using ULL = int64_t;
using P = pair<LL, LL>;
#define rep(i, n) for (LL i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define DEBUG

LL n;
LL abc[3];

#define HUGE (9999999LL)
LL dfs(const LL depth,
       vector<LL>& which,
       const vector<LL>& len) {
  if (depth == n) {
    LL count[] = {(LL)0, (LL)0, (LL)0, (LL)0};
    LL len_sum[] = {(LL)0, (LL)0, (LL)0, (LL)0};
    rep(i, n) {
      count[which[i]]++;
      len_sum[which[i]] += len[i];
    }
    if (count[0] == 0 || count[1] == 0 || count[2] == 0) {
      return HUGE;
    }

    LL cost = 0;
    rep(i, 3) {
      cost += (count[i] - 1) * 10;
      cost += abs(len_sum[i] - abc[i]) * 1;
    }
//    rep(i, n) {
//      cout << which[i] << "\t";
//    }
//    cout << " : " << cost << "\n";
    return cost;
  }

  LL ans = (LL)HUGE;
  rep (i, 4) {
    which.at(depth) = i;
    LL v = dfs(depth + 1, which, len);
    ans = min(ans, v);
  }
  return ans;
}

int main() {
  cin >> n >> abc[0] >> abc[1] >> abc[2];
  vector<LL> which(n, -1);
  vector<LL> len(n, -1);
  rep (i, n) {
    cin >> len.at(i);
  }

  LL ans = dfs(0, which, len);
  cout << ans << endl;

  #ifdef DEBUG
  // cout << 123 << endl;
  #endif
}

