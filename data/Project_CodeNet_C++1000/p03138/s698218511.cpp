#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
//constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
  }
  ll beki = 1LL<<60;
  ll ans = 0, ans2 = 0;
  bool under = false;
  REPR(i, 60){
    int cnt = 0;
    REP(j, N){
      if(A[j] >> i & 1){
        cnt++;
      }
    }
    if(under){
      ans2 += beki * max(cnt, N-cnt);
    }
    if(K >> i & 1){
      ans2 = max(ans2, ans+cnt*beki);
    }
    if(K>>i & 1) under = true;

    if(K>>i & 1){
      ans += (N-cnt) * beki;
    }
    else{
      ans += cnt * beki;
    }
    beki = beki >> 1;
  }
  cout << max(ans, ans2) << endl;
  return 0;
}
