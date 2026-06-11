#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
queue<int> Q[6];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  if (N == 3) {
    cout << "2 5 63\n";
    return 0;
  }
  if (N == 4) {
    cout << "2 5 20 63\n";
    return 0;
  }
  // 2,4,3,0
  for (int x=2; x<=30000; x++) if ((x%2 == 0) || (x%3 == 0)) {
    Q[x%6].push(x);
  }
  //cout<<Q[2].size()<<"*"<<Q[4].size()<<"*"<<Q[3].size()<<"\n";
  for (int two=1; two<=Q[2].size(); two++) {
    for (int four=0; four<=Q[4].size() && two+four<=N; four++) {
      if ((2*two+4*four)%6) continue;
      int three = min((int)Q[3].size(), N-(two-four));
      if (three%2) three--;
      if (three == 0) continue;
      //for (int three=0; three<=Q[3].size() && two+four+three<=N; three+=2) {
        int zero = N-(two+four+three);
        if (zero > Q[0].size()) continue;

        rep(_, two) { cout << Q[2].front() << " "; Q[2].pop(); }
        rep(_, four) { cout << Q[4].front() << " "; Q[4].pop(); }
        rep(_, three) { cout << Q[3].front() << " "; Q[3].pop(); }
        rep(_, zero) { cout << Q[0].front() << " "; Q[0].pop(); }
        cout << "\n";
        return 0;
      //}
    }
  }
  abort();
  return 0;
}
