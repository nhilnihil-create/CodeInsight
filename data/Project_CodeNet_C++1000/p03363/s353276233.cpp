#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;


void solve(long long N, std::vector<long long> A){
  vector<ll> v(N+1, 0);
  map<ll,ll> m;
  ll ans = 0;
  m[0] = 0;
  rep(i, N) v[i+1] += v[i]+A[i];
  for(int i=1; i<=N; i++) {
    if(m.find(v[i])!=m.end()) {
      m[v[i]]++;
      ans += m[v[i]];
    } else {
      m[v[i]] = 0;
    }
  }

  std::cout << ans << std::endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
