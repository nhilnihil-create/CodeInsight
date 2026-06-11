#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int N, A, B, C;
ll ANS = INF;


void dfs(int c, vector<int> &seq, vector<int> &vec) {
  if (c == N) {
    vector<int> res(4, 0);
    ll ans = 0;
    set<int, greater<int>> val;
    REP(i, N) {
      if (seq[i] == 3) {
        continue;
      }
      val.insert(seq[i]);
    }
    if (val.size() < 3) {
      return;
    }
    REP(i, N) {
      if (seq[i] == 3) {
        continue;
      }
      if (res[seq[i]] > 0) {
        ans += 10;
      }
      res[seq[i]] += vec[i];
    }
    ans += abs(A - res[0]);
    ans += abs(B - res[1]);
    ans += abs(C - res[2]);
    ANS = min(ANS, ans);
    return;
  }
  REP(i, 4) {
    seq[c] = i;
    dfs(c+1, seq, vec);
  }
}

int main()
{
  cin >> N >> A >> B >> C;
  vector<int> vec(N, 0);
  vector<int> seq(N, 0);
  REP(i, N) {
    cin >> vec[i];
  }
  dfs(0, seq, vec);
  cout << ANS << endl;
  return 0;
}