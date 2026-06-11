#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, long long K, std::vector<long long> a){
  vector<ll> v(N+1, 0);
  for(ll i=0; i<N; i++) {
    v[i+1]+=v[i]+a[i];
  }

  ll ans = 0;
  for(ll i=50; i>=0; i--) {
    ll k=0;
    for(ll l=0; l<N+1; l++) {
      for(ll r=l+1; r<N+1; r++) {
	ll sum=v[r]-v[l];
	//std::cout << sum << std::endl;
	if(((ans + (1LL<<i)) & sum) == (ans + (1LL<<i))) {
	  k++;
	}
      }
    }
    if(k>=K)
      ans += (1LL<<i);
  }
  std::cout << ans << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long K;
  scanf("%lld",&K);
  std::vector<long long> a(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&a[i]);
  }
  solve(N, K, std::move(a));
  return 0;
}

