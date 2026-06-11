#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  map<ll, set<int> > mp;
  rep(i, N) {
    if(!mp.count(A[i])) mp[A[i]] = set<int>();
    mp[A[i]].insert(i);
  }
  vector<bool> paired(N, false);
  int ans = 0;
  for(int i=N-1; i>=0; i--) {
    if(paired[i]) continue;
    int digit = ceil(log2(A[i]));
    ll pair = (ll)pow(2, digit) - A[i];
    if(pair == 0) pair = A[i];
    if(mp.count(pair)) {
      if(mp[pair].size() == 0) {
        mp.erase(pair);
      } else {
        for(auto pairIdx: mp[pair]) {
          if(pairIdx == i) continue;
          if(paired[pairIdx]) {
            mp[pair].erase(pairIdx);
            if(mp[pair].size() == 0) mp.erase(pair);
          } else {
            paired[i] = true;
            paired[pairIdx] = true;
            // cout << A[i] << ' ' << A[pairIdx] << endl;
            mp[pair].erase(pairIdx);
            if(mp[pair].size() == 0) mp.erase(pair);
            ans++;
            break;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

