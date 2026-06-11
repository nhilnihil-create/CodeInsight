#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define INF (1LL<<60)
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

void rec(vector<ll> &b)
{
  if(b.size() == 0) return;
  bool ok = false;
  for(ll i = b.size()-1; i >= 0; i--) {
    if(b[i] == i + 1) {
      ok = true;
      b.erase(b.begin() + i);
      rec(b);
      cout << i + 1 << endl;
      break;
    }
  }
  if(!ok) {
    cout << -1 << endl;
    exit(0);
  }
}

void solve()
{
  ll N; cin >> N;
  vector<ll> b(N); rep(i, N) cin >> b[i];
  rec(b);
}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
