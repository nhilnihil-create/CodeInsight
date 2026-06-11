#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, int> P;
const ll Mod = 1000000007;
const ll INF = Mod * 100LL;
int main() {
  int N,K,Q;
  cin >> N >> K >> Q;
  ll ans = INF;
  vector<ll> A(N);
  vector<P> As(N);
  set<int> Set;
  Set.insert(-1);
  Set.insert(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    As[i].F = A[i];
    As[i].S = i;
  }
  sort(As.begin(),As.end());
  for (int i = 0; i < N; i++) {
    multiset<ll> Sum;
    int p = 0;
    for (auto itr = next(Set.begin(),1); p <= i; itr++) {
      p++;
      auto pitr = prev(itr,1);
      multiset<ll> S;
      for (int j = *pitr+1; j < *itr; j++) {
        S.insert(A[j]);
      }
      
      int len = 0;
      int sz = (int)S.size();
      if (*pitr == -1 && *itr == N) {
        len = max(len,sz);
      } else if (*pitr == -1 || *itr == N) {
        len = max(len,sz - K + 1);
      } else {
        len = max(len,sz - K + 1);
      }
      int cnt = 0;
      for (auto itr = S.begin(); cnt < len; itr++) {
        Sum.insert(*itr);
        cnt++;
      }
    }
    if ((int)Sum.size() >= Q) {
      ans = min(ans,*(next(Sum.begin(),Q-1)) - *(Sum.begin()));
      Set.insert(As[i].S);
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}