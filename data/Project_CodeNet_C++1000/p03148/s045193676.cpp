#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

int main(){
  int N, K;
  cin >> N >> K;
  ll t, d;
  vector<ll> A, king(N, -1);
  int cnt = 0;
  REP(i, N){
    cin >> t >> d;
    t--;
    if(king[t] == -1){
      cnt++;
    }
    if(king[t] < d){
      swap(d, king[t]);
    }
    A.push_back(d);
  }
  sort(A.rbegin(), A.rend());
  A.insert(A.begin(), 0);
  REP(i, A.size()-1){
    A[i+1] += A[i];
  }
  sort(king.rbegin(), king.rend());
  king.insert(king.begin(), 0);
  REP(i, king.size()-1){
    king[i+1] += king[i];
  }
  ll ans = 0;
  FOR(i, 1, min(cnt, K)+1){
    // cerr << "i:" << i << " king[i]:" << king[i] << " A[K-i]:" << A[K-i] << endl;
    ll pt = ll(i)*i;
    pt += king[i] + A[K-i];
    ans = max(ans, pt);
  }
  cout << ans << endl;
  return 0;
}
