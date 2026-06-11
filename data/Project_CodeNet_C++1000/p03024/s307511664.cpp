#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;
const string YES = "YES";
const string NO = "NO";

void solve(string S) {
  int lose(0);
  REP(i, S.length())
    if (S[i] == 'x')
      lose++;
  cout << (lose < 8 ? YES : NO) << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  solve(S);

  return 0;
}
