#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(ll N, vector<string> S) {
  unordered_map<char, ll> count;
  REP(i, N) {
    const char head = S[i].front();
    switch (head) {
    case 'M':
    case 'A':
    case 'R':
    case 'C':
    case 'H':
      count[head]++;
      break;
    default:
      break;
    }
  }

  vector<ll> num(5);
  num[0] = count['M'];
  num[1] = count['A'];
  num[2] = count['R'];
  num[3] = count['C'];
  num[4] = count['H'];
  ll ans(0);

  ll comb = (1LL << 3) - 1;
  while (comb < (1LL << 5)) {
    ll ans_comb(1);
    REP(i, 5)
      if ((1LL << i) & comb)
	ans_comb *= num[i];
    ans += ans_comb;
    ll x = comb & -comb;
    ll y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
  }
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<string> S(N);
  REP(i, N) {
    cin >> S[i];
  }

  solve(N, move(S));

  return 0;
}
