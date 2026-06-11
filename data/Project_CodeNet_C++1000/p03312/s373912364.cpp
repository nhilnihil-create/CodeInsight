#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

//#define INF 1e9
const ll INF = 1LL << 61;
int main(){
  int N;
  cin >> N;
  vector<ll> A(N), sum(N+1, 0);
  REP(i, N){
    cin >> A[i];
  }
  REP(i, N){
    sum[i+1] = sum[i] + A[i];
  }
  ll ans = INF;
  int l = 1, r = 2+1;
  FOR(i, 2, N-1) {
    if(i == r) r++;
    while(l< i-1 && abs(sum[i] - 2*sum[l]) > abs(sum[i] - 2*sum[l+1])){
      l++;
    }
    ll R = sum[N] - sum[i];
    while(r < N-1 && abs(R - 2*(sum[r]-sum[i])) > abs(R-2*(sum[r+1]-sum[i]))){
      r++;
    }
    ll MAX = max(max(sum[i]-sum[l], sum[l]), max(sum[N] - sum[r], sum[r] - sum[i]));
    ll MIN = min(min(sum[i]-sum[l], sum[l]), min(sum[N] - sum[r], sum[r] - sum[i]));
    ans = min(ans, abs(MAX-MIN));
  }
  cout << ans << endl;
  return 0;
}
