#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

// -------------------------------------------


void solve(long long N, long long M, std::vector<long long> x, std::vector<long long> y, std::vector<long long> z){
  ll ans = 0;
  rep(i,8) {
    vector<ll> v;
    rep(j,N) {
      ll sum = 0;
      if(i&1) sum+=x[j];
      else sum-=x[j];
      if(i&2) sum+=y[j];
      else sum-=y[j];
      if(i&4) sum+=z[j];
      else sum-=z[j];
      v.push_back(sum);
    }
    sort(v.rbegin(), v.rend());
    ll tmp = 0;
    rep(j,M) tmp+=v[j];
    ans = max(ans, tmp);
  }
  std::cout << ans << std::endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    std::vector<long long> z(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
        scanf("%lld",&z[i]);
    }
    solve(N, M, std::move(x), std::move(y), std::move(z));
    return 0;
}
