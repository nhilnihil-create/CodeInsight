#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;
const string YES = "YES";
const string NO = "NO";

void solve(ll N, vector<ll> D, ll M, vector<ll> T) {
  unordered_map<ll, ll> problems;
  REP(i, N)
    problems[D[i]]++;

  REP(i, M)
    if (problems[T[i]] > 0)
      problems[T[i]]--;
    else {
      cout << NO << endl;
      return;
    }
  cout << YES << endl;
  return;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<ll> D(N);
  REP(i, N) {
    cin >> D[i];
  }
  ll M;
  cin >> M;
  vector<ll> T(M);
  REP(i, M) {
    cin >> T[i];
  }

  solve(N, move(D), M, move(T));

  return 0;
}
